#include <iostream>
#include <string>
#include <vector>
using namespace std;

int vectorOrdenado(vector<int> numeros) {
    for (int i = 0; i < numeros.size() - 1; i++) {
        if (numeros[i] > numeros[i + 1]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    vector<int> numeros;
    int ordenado;

    cout << "Digite 5 numeros inteiros: ";
    for (int i = 0; i < 5; i++) {
        int numero;
        cin >> numero;
        numeros.push_back(numero);
    }

    ordenado = vectorOrdenado(numeros);

    if (ordenado == 1) {
        cout << "O vetor esta ordenado." << endl;
    } else {
        cout << "O vetor nao esta ordenado." << endl;
    }

    return 0;
}