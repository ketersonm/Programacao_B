#include <iostream>
#include <string>

using namespace std;

#include "MeusTipos.h"

int main(){
    string numeroCpf;
    cout << "Digite o numero do CPF: ";
    cin >> numeroCpf;

    if(ValidadorCPF(numeroCpf)){
        cout << "CPF valido!" << endl;
    } else {
        cout << "CPF invalido!" << endl;
    }

    return 0;
}