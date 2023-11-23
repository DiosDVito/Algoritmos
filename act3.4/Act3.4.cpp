#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;


struct LogEntry {
    string date;
    string time;
    string ip;
    string port;
};


struct Node {
    int accesses;
    string port;
    Node* left;
    Node* right;


    Node(int accesses, const string& port) : accesses(accesses), port(port), left(nullptr), right(nullptr) {}
};


void insert(Node*& root, const string& port) {
    if (!root) {
        root = new Node(1, port);
        return;
    }


    if (port < root->port) {
        insert(root->left, port);
    } else if (port > root->port) {
        insert(root->right, port);
    } else {
        // Incrementa el cont
        root->accesses++;
    }
}


void processLogFile(const string& filename, Node*& root) {
    ifstream inputFile(filename);
    string line;


    while (getline(inputFile, line)) {
        istringstream iss(line);
        LogEntry entry;
        iss >> entry.date >> entry.time >> entry.ip;


        iss.ignore(256, ':');  // Se salta todo hasta ':'
        iss >> entry.port;


        insert(root, entry.port);  // Incrementa cont accesos
    }


    inputFile.close();
}


void inOrderTraversal(Node* root, multiset<pair<int, string>>& result) {
    if (root) {
        inOrderTraversal(root->left, result);
        result.insert({root->accesses, root->port});
        inOrderTraversal(root->right, result);
    }
}


int main() {
    Node* root = nullptr;
    processLogFile("bitacora.txt", root);


    // Busca los 5
    multiset<pair<int, string>> sortedPorts;
    inOrderTraversal(root, sortedPorts);


    // Top 5
    ofstream outputFile("bitacorafixed.txt");
    int count = 0;


    for (auto it = sortedPorts.rbegin(); it != sortedPorts.rend() && count < 5; ++it) {
        outputFile << "Port: " << it->second << ", Accesses: " << it->first << endl;
        count++;
    }


    delete root;


    outputFile.close();


    return 0;
}
