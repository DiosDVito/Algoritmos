#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
using namespace std;

struct LogEntry {
     string mes;
    int dia;
     string hora;
     string direccionIP;
     string razonFalla;
};

 unordered_map< string, LogEntry> leerBitacora(const  string& archivo) {
     unordered_map< string, LogEntry> tablaHash;
     ifstream file(archivo);

    if (file.is_open()) {
         string mes, hora, direccionIP, razonFalla;
        int dia;
        while (file >> mes >> dia >> hora >> direccionIP) {
             getline(file, razonFalla);
            tablaHash[direccionIP] = {mes, dia, hora, direccionIP, razonFalla};
        }
        file.close();
    } else {
         cerr << "No se pudo abrir el archivo de bitácora." <<  endl;
    }

    return tablaHash;
}

 string obtenerResumen(const  unordered_map< string, LogEntry>& tablaHash, const  string& direccionIP) {
    auto iter = tablaHash.find(direccionIP);
    if (iter != tablaHash.end()) {
        const LogEntry& entry = iter->second;
        return  entry.mes + " " + to_string(entry.dia) + " " + entry.hora + " " + entry.direccionIP + " " + entry.razonFalla;
    } else {
        return "Entrada no encontrada para la dirección IP: " + direccionIP;
    }
}

int main() {
    const  string archivoBitacora = "bitacora.txt";
     unordered_map< string, LogEntry> tablaBitacora = leerBitacora(archivoBitacora);

     cout << "Ingrese la dirección IP a buscar: ";
     string direccionIPBuscar;
     cin >> direccionIPBuscar;

     string resumenEncontrado = obtenerResumen(tablaBitacora, direccionIPBuscar);

     cout << "Resumen para la dirección IP " << direccionIPBuscar << ":\n" << resumenEncontrado <<  endl;

    return 0;
}