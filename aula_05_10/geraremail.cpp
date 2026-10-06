#include <iostream>
#include <string>

using namespace std;

#include "MeusTipos.h"

int main() {
    string nome1;
    string nome2;
    cout << "Digite seu primeiro nome: ";
    cin >> nome1;
    cout << "Digite o seu sobrenome: ";
    cin >> nome2;

    cout << "O seu email eh: " << nome1 << "." << nome2 << "@ufn.edu.br" << endl;
    return 0;
}