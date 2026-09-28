#include <iostream>
#include <string>

using namespace std;

int contaLetras(string nome, string letra) {
    int quantidade = 0;
    for (int i = 0; i < nome.size(); i++) {
        if (nome[i] == letra[0]) {
            quantidade++;
        }
    }
    return quantidade;
}


int main() {
    string nome, letra;
    int quantidade;

    cout << "Digite um nome: ";
    cin >> nome;
    cout << "Digite uma letra: ";
    cin >> letra;
    quantidade = contaLetras(nome, letra);
    cout << "A letra '" << letra << "' aparece " << quantidade << " vezes no nome '" << nome << "'." << endl;

    return 0;
}