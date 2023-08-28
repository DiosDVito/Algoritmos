#include <iostream>
#include <fstream>
#include "string"
#include <vector>

using namespace std;


struct linea{
    string mes;
    int dia;
    string hora;
    string ip;
    string razon;
};

bool mayor(linea a1, linea a2){
    if (a1.dia == a2.dia) {
        return a1.hora < a2.hora;
    }
    return a1.dia < a2.dia;
}


void bubbleSort(vector<linea>&lineas){
    int n=lineas.size();

    for (int i = 0; i < n - 1; i++){
        for(int j=0; j<n-i-1;j++){

            if (mayor(lineas[j], lineas[j+1])){
                swap(lineas[j], lineas[j + 1]); 
            }
        }
    }
}
//OpO
int main() {
    vector<linea> lineas;
    ifstream text("bitacora.txt");
    ofstream textOut("bitacoraArreglada.txt");
    linea agg;

    while(text >> agg.mes >> agg.dia >> agg.hora >> agg.ip){
        getline(text, agg.razon);
        lineas.push_back(agg);
    }

    bubbleSort(lineas);

    string inicio, final;
    cout << "Dame la fecha de inicio (mes dia hora): ";
    getline(cin, inicio);

    cout << "Dame la fecha de fin (mes dia hora): ";
    getline(cin, final);

    textOut << "Accesos entre " << inicio << " y " << final << endl;

    for (linea agg : lineas) {
        string fechaagg = agg.mes + " " + to_string(agg.dia) + " " + agg.hora;
        if (fechaagg >= inicio && fechaagg <= final) {
            textOut << agg.mes << " " << agg.dia << " " << agg.hora << " " << agg.ip << " " << agg.razon << "\n";
        }
    }
    
    text.close();
    textOut.close();

    return 0;
}