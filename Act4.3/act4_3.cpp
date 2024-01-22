#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un grafo
class Graph {
public:
    map<int, vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    int fanOut(int u) {
        return adjList[u].size();
    }
};

int main() {
    ifstream file("bitacora.txt");
    string line;
    Graph ipGraph;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string month, time, ip, reason;
        int day;
        ss >> month >> day >> time >> ip >> reason;

        // Separar la IP y construir el grafo
        stringstream ipStream(ip);
        string segment;
        vector<int> ipSegments;
        while (getline(ipStream, segment, '.')) {
            ipSegments.push_back(stoi(segment));
        }

        for (size_t i = 0; i < ipSegments.size() - 1; ++i) {
            ipGraph.addEdge(ipSegments[i], ipSegments[i + 1]);
        }
    }

    file.close();

    // Calcular el fan-out de cada nodo
    map<int, int> fanOuts;
    for (auto &pair : ipGraph.adjList) {
        fanOuts[pair.first] = ipGraph.fanOut(pair.first);
    }

    //Esta parte del código identifica el nodo con el mayor fan-out. 
    //Asumimos que este nodo es el segmento inicial de la dirección IP del boot master.
    auto maxFanOutIt = max_element(fanOuts.begin(), fanOuts.end(), 
                                   [](const pair<int, int>& a, const pair<int, int>& b) {
                                       return a.second < b.second;
                                   });

    cout << "Nodo con mayor fan-out: " << maxFanOutIt->first << " (fan-out: " << maxFanOutIt->second << ")" << endl;

    return 0;
}
