#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "meusTipos.h"

// typedef struct {
// string placa;
// string cor;
// string horaEntrada;
// } Veiculo;

int main()
{
    vector<Veiculo> garagem;
    int opcao;
    string placa, cor, horaEntrada;

    do
    {
        cout << "Menu de opcoes:\n";
        cout << "1 - Adicionar veiculo\n";
        cout << "2 - Listar veiculos\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

        switch (opcao)
        {
        case 1:
            cout << "Digite a placa do veiculo: ";
            getline(cin, placa);
            cout << "Digite a cor do veiculo: ";
            getline(cin, cor);
            cout << "Digite a hora de entrada do veiculo: [hh:mm] ";
            getline(cin, horaEntrada);

            garagem.push_back({placa, cor, horaEntrada});

            break;
        case 2:
            cout << "Veiculos na garagem:\n";
            for (int i = 0; i < garagem.size(); i++)
            {
                cout << "Placa: " << garagem[i].placa << ", Cor: " << garagem[i].cor << ", Hora de Entrada: " << garagem[i].horaEntrada << endl;
            }
            break;
        case 0:
            cout << "Saindo do programa.\n";
            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);
    return 1;
}
