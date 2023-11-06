#include <iostream>
#include <vector>

class PriorityQueue {
private:
    std::vector<int> pila;

    // Ajustar hacia arriba
    void heapifyUp(int index) {
        while (index > 0) {
            int padre = (index - 1) / 2;
            if (pila[padre] < pila[index]) {
                std::swap(pila[padre], pila[index]);
                index = padre;
            } else {
                break;
            }
        }
    }

    // Ajustar hacia abajo
    void heapifyDown(int index) {
        int size = pila.size();
        while (true) {
            int hijoIzq = 2 * index + 1;
            int hijoDer = 2 * index + 2;
            int largest = index;

            if (hijoIzq < size && pila[hijoIzq] > pila[largest]) {
                largest = hijoIzq;
            }

            if (hijoDer < size && pila[hijoDer] > pila[largest]) {
                largest = hijoDer;
            }

            if (largest != index) {
                std::swap(pila[index], pila[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insertar
    void push(int value) {
        pila.push_back(value);
        heapifyUp(pila.size() - 1);
    }

    // Eliminar
    void pop() {
        if (!empty()) {
            pila[0] = pila.back();
            pila.pop_back();
            heapifyDown(0);
        }
    }

    // # con mayor prioridad
    int top() {
        if (!empty()) {
            return pila[0];
        }
        throw std::out_of_range("La cola de prioridad está vacía.");
    }

    // Verificar si la cola está vacía
    bool empty() {
        return pila.empty();
    }

    // Tamaño cola
    std::size_t size() {
        return pila.size();
    }
};

int main() {
    PriorityQueue mayor_prior;

    mayor_prior.push(5);
    mayor_prior.push(2);
    mayor_prior.push(10);
    mayor_prior.push(7);
    mayor_prior.push(11);
    mayor_prior.push(20);

    std::cout << "Elemento con mayor prioridad: " << mayor_prior.top() << std::endl;

    mayor_prior.pop();

    std::cout << "Elemento con mayor prioridad después de eliminar uno: " << mayor_prior.top() << std::endl;

    return 0;
}
