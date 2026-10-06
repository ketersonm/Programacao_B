#include <iostream>
#include <string>

using namespace std;

#include "MeusTipos.h"

int main() {
    string DataValida;


    cout << " DIgite uma data no formato dd/mm/aaaa: ";
    cin >> DataValida;

    if(ValidadorDatas(DataValida)) {
        cout << "Data valida!" << endl;
    } else {
        cout << "Data invalida!" << endl;
    }
    return 1;
}