#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <thread>
using namespace std;

class Proceso {
public:
    int id;
    int tiempoLlegada; // En milisegundos
    int duracionBurst; // En milisegundos
    int duracionRestante; // En milisegundos
    int tiempoFinalizacion;
    int tiempoEspera;
    int tiempoRespuesta;
    bool completado; // Indica si el proceso ha completado su ejecución

    Proceso(int id, int llegada, int burst) :
        id(id), tiempoLlegada(llegada), duracionBurst(burst),
        duracionRestante(burst), tiempoFinalizacion(0),
        tiempoEspera(0), tiempoRespuesta(-1), completado(false) {}
};

void roundRobin(vector<Proceso>& procesos, int quantum) {
    int tiempoActual = 0;
    queue<int> cola;
    vector<bool> enCola(procesos.size(), false);

    // Añadir procesos que llegan en tiempo 0
    for (int i = 0; i < procesos.size(); i++) {
        if (procesos[i].tiempoLlegada == tiempoActual) {
            cola.push(i);
            enCola[i] = true;
        }
    }

    while (!cola.empty()) {
        int i = cola.front();
        cola.pop();
        enCola[i] = false;

        if (!procesos[i].completado) { // Verificar si el proceso ya está completado
            // Simular la ejecución del proceso
            int tiempoEjecucion = min(procesos[i].duracionRestante, quantum);
            this_thread::sleep_for(chrono::milliseconds(tiempoEjecucion));
            cout << "Proceso " << procesos[i].id << " ejecutándose por " << tiempoEjecucion << " ms" << endl;
            tiempoActual += tiempoEjecucion;
            procesos[i].duracionRestante -= tiempoEjecucion;

            if (procesos[i].tiempoRespuesta == -1) {
                procesos[i].tiempoRespuesta = tiempoActual - procesos[i].tiempoLlegada;
            }

            // Añadir procesos que llegan durante la ejecución
            for (int j = 0; j < procesos.size(); j++) {
                if (!enCola[j] && procesos[j].tiempoLlegada <= tiempoActual && procesos[j].duracionRestante > 0) {
                    cola.push(j);
                    enCola[j] = true;
                }
            }

            if (procesos[i].duracionRestante > 0) {
                cout << "Proceso " << procesos[i].id << " pausado con " << procesos[i].duracionRestante << " ms restantes" << endl;
                cola.push(i);
                enCola[i] = true;
            } else {
                procesos[i].tiempoFinalizacion = tiempoActual;
                procesos[i].tiempoEspera = procesos[i].tiempoFinalizacion - procesos[i].tiempoLlegada - procesos[i].duracionBurst;
                procesos[i].completado = true; // Marcar el proceso como completado
                cout << "Proceso " << procesos[i].id << " completado" << endl;
            }
        }
    }
}

int main() {
    vector<Proceso> procesos = {
        Proceso(1, 0, 500),
        Proceso(2, 100, 300),
        Proceso(3, 200, 800),
        // Agrega más procesos según sea necesario
    };

    int quantum = 200;
    roundRobin(procesos, quantum);

    // Mostrar resultados
    for (const auto& p : procesos) {
        cout << "Proceso " << p.id << ": Tiempo de Espera = " << p.tiempoEspera
             << " ms, Tiempo de Respuesta = " << p.tiempoRespuesta
             << " ms, Tiempo de Finalización = " << p.tiempoFinalizacion << " ms" << endl;
    }

    return 0;
}
