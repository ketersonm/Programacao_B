#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "meusTipos.h"

int main()
{
    vector<conta> banco;
    int opcao, indice, valor;
    conta contaTMP;

    do
    {
        cout << "Menu de Opcoes:" << endl;
        cout << "1. Adicionar conta" << endl;
        cout << "2. Depositar" << endl;
        cout << "3. Mostrar todas as contas" << endl;
        cout << "4. Sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "Digite o numero da conta: ";
                cin >> contaTMP.numero;
                cout << "Digite o saldo da conta: ";
                cin >> contaTMP.saldo;
                banco.push_back(contaTMP);
                break;
            case 2:
                cout << "Indices disponiveis: " << banco.size() << endl;
                cout << "Digite o indice da conta: ";
                cin >> indice;
                if (indice >= 0 && indice < banco.size()) {
                    cout << "Digite o valor do deposito: ";
                    cin >> valor;
                    banco[indice].saldo += valor;
                } else {
                    cout << "Indice invalido!" << endl;
                }
                break;
            case 3:
                if (banco.empty()) {
                    cout << "Nenhuma conta cadastrada." << endl;
                } else {
                    for (int i = 0; i < banco.size(); i++) {
                        cout << "Conta " << i << ": Numero: " << banco[i].numero << ", Saldo: " << banco[i].saldo << endl;
                    }
                }
                break;
            case 4:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 4);
}
