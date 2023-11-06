//DC, DE, LL, SA, DV
#include <iostream>
#include <vector>

using namespace std;

class priority_queue {
    private:
     int size;
    public:
    priority_queue(){//inicializamos el valor en 0
        size = 0;
    };
    vector<int> heap;   

    //cuando insertamos un nuevo elemento
    void heapify_i(int index) {
        if (index == 0) {
            return;
        }
        int parent_index = (index-1)/2;

        if (heap[parent_index] < heap[index]) { //cambiamos si es mas grande que el padre
            swap(heap[parent_index], heap[index]);
            heapify_i(parent_index);
        }
    }
   
    //cuando sacamos un elemento
    void heapify_del(int index) {
        int leftChild = 2*index+1;
        int rightChild = 2*index+2;
        int largestChild = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largestChild]) {  //compara el elemento actual con sus hijos para encontrar el hijo más grande
            largestChild = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largestChild]) { 
            largestChild = rightChild;
        }

        if (largestChild != index) {
            swap(heap[index], heap[largestChild]);
            heapify_del(largestChild);
        }
    }

        
    void push(int value) {
        heap.push_back(value);
        heapify_i(heap.size() -1);
    }

    int top() {
        if (heap.empty()) {
            return -1;
        }
        return heap[0];
    }

    int sizePq() {
        return heap.size();
    }

    int pop() {
        if (heap.empty()) {
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_del(0);

        return root;
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    priority_queue heap;
    //insertamos los valores
    heap.push(55);
    heap.push(9);
    heap.push(21);
    heap.push(67);
    heap.push(43);  
    heap.push(1);

    //iteramos para mostrarlo
    for(int i=0; i<heap.heap.size(); i++){
        cout << heap.heap[i]<<",";
    }
    heap.pop();
    cout <<endl;
    //checamos si despues del pop ya lo borro
    //checamos si el metodo top funciona
    //iteramos para mostrarlo
    for(int i=0; i<heap.heap.size(); i++){
        cout << heap.heap[i]<<",";
    }
    //probamos los metodos
    cout <<endl;
    cout<< heap.sizePq();
    cout <<endl;
    cout<< heap.empty();
    cout <<endl;
    cout<< heap.top();

    return 0;
}

