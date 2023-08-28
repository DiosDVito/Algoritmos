#include <iostream>
using namespace std;


int sumaIterativa(int n){
    int sumaI = 0;
    for (int i = 1; i <= n; i = i+1){
        sumaI += i;
    }
    return sumaI;
}

int sumaRecursiva(int n){
    if (n == 1){
        return 1;
    }
    else{
        return n + sumaRecursiva(n - 1);
    }
}

int sumaDirecta(int n){
    int sumaD = n*(n+1)/2;
    return sumaD;
}

int main(){
    int n;
    cout << "Ingrese un numero 'n': ";
    cin >> n;

    cout << "La suma de los numeros de 1 a " << n << " de forma iterativa es: " << sumaIterativa(n) << endl;
    cout << "La suma de los numeros de 1 a " << n << " de forma recursiva es: " << sumaRecursiva(n) << endl;
    cout << "La suma de los numeros de 1 a " << n << " de forma directa es: " << sumaDirecta(n) << endl;
    return 0;
}

