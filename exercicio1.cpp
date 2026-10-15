#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
void popularVetor(vector<int> &v, int qtd, int inicio, int fim) {
    
    int numero;
    for (int i = 0; i < qtd; i++) {
        numero = (rand() % fim) - inicio;
        v.push_back(numero);
    }
}

void exibirVetor(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

void exercicio1(vector<int> vetorA, vector<int> vetorB) {
    for (int i = 0; i < vetorA.size(); i++) {
        for (int j = 0; j < vetorB.size(); j++) {
            if (vetorA[i] == vetorB[j]) {
                cout << "O valor " << vetorA[i] << " esta presente nos dois vetores." << endl;
                break;
            }
        }
    }
}

int main () {
    srand(time(NULL));
    vector<int> vetorA;
    vector<int> vetorB;
    
    popularVetor(vetorA, 10, 1, 10);
    cout << "Vetor A: \n";
    exibirVetor(vetorA);
    popularVetor(vetorB, 5, 1, 10);
    cout << "Vetor B: \n";
    exibirVetor(vetorB);

    cout << "Valores presentes nos dois vetores: \n";
    exercicio1(vetorA, vetorB);
   
    return 0;
}