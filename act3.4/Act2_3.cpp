#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct linea {
    string mes;
    int dia;
    string hora;
    string ip;
    string razon;
};

struct Nodo {
    linea data;
    Nodo* prev;
    Nodo* next;
    Nodo(const linea& data) : data(data), prev(nullptr), next(nullptr) {}
};

// Función para comparar dos direcciones IP numéricamente
bool compararIP(const string& ip1, const string& ip2) {
    stringstream ss1(ip1), ss2(ip2);
    int octet1[4], octet2[4];
    char dot;

    for (int i = 0; i < 4; i++) {
        ss1 >> octet1[i] >> dot;
        ss2 >> octet2[i] >> dot;

        if (octet1[i] != octet2[i]) {
            return octet1[i] < octet2[i];
        }
    }

    return false; // Igualdad en todas las partes
}

int quickPartition(vector<Nodo*>& nodos, int low, int high) {
    linea pivot = nodos[high]->data;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (compararIP(nodos[j]->data.ip, pivot.ip)) {
            i++;
            swap(nodos[i], nodos[j]);
        }
    }

    swap(nodos[i + 1], nodos[high]);

    return i + 1;
}

void quickSort(vector<Nodo*>& nodos, int low, int high) {
    if (low < high) {
        int pivotIndex = quickPartition(nodos, low, high);
        quickSort(nodos, low, pivotIndex - 1);
        quickSort(nodos, pivotIndex + 1, high);
    }
}

int main() {
    vector<Nodo*> nodos;
    ifstream text("bitacora2.txt");
    ofstream textOut("bitacoraFixed.txt");
    linea agg;

    while (text >> agg.mes >> agg.dia >> agg.hora >> agg.ip) {
        getline(text, agg.razon);
        Nodo* nuevoNodo = new Nodo(agg);
        nodos.push_back(nuevoNodo);
    }

    int low = 0;
    int high = nodos.size() - 1;

    quickSort(nodos, low, high);

    string inicio, final;
    cout << "Dame la ip de inicio: ";
    getline(cin, inicio);

    cout << "Dame la ip final: ";
    getline(cin, final);

    textOut << "Accesos entre " << inicio << " y " << final << endl;

    for (Nodo* nodo : nodos) {
        if (compararIP(nodo->data.ip, final) && compararIP(inicio, nodo->data.ip)) {
            textOut << nodo->data.mes << " " << nodo->data.dia << " " << nodo->data.hora << " " << nodo->data.ip << nodo->data.razon << "\n";
        }
    }

    for (Nodo* nodo : nodos) {
        delete nodo;
    }

    nodos.clear();
    text.close();
    textOut.close();
}
