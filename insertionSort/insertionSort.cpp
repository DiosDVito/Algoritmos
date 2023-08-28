#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i = i + 1) {
        int key = arr[i];
        int j = i - 1;

        // Mover los elementos de la sublista ordenada hacia adelante
        // para hacer espacio para la inserción del elemento actual.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key; // Insertar el elemento en su posición correcta.
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 24, 100, 23, 52, 100};
    
    std::cout << "Arreglo original: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(arr);

    std::cout << "Arreglo ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
