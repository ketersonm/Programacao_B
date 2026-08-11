#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;
#include "meusTipos.h"

// typedef struct {
// string placa;
// string cor;
// string horaEntrada;
// string horaSaida;
// } Veiculo;

int main()
{
    vector<Veiculo> garagem;
    int opcao;
    string placa, cor, horaEntrada, horaSaida;
    int totalMinutos;

    do
    {
        cout << "Menu de opcoes:\n";
        cout << "1 - Adicionar veiculo\n";
        cout << "2 - Listar veiculos\n";
        cout << "3 - Retirar veiculo\n";
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
        case 3:
        cout << "Digite a placa do carro que deseja retirar: ";
        getline(cin, placa);
        for ( int i = 0; i < garagem.size(); i++)
        {
            if (garagem[i].placa == placa)
            {
               garagem.erase(garagem.begin() + i);
               cout << "Veiculo retirado com sucesso.\n";
               break;
            }
        }


        break;
        case 0:
            cout << "Saindo do programa.\n";
            cout << "Digite a placa do veiculo que deseja retirar: \n";
            getline(cin, placa);
            for (int i = 0; i < garagem.size(); i++)
            {
                if (garagem[i].placa == placa)
                {
                    cout << "Veiculo encontrado \n";
                    cout << "Digite a hora de saida do veiculo: [hh:mm] \n";
                    getline(cin, horaSaida);
                    garagem[i].horaSaida = horaSaida;
                    totalMinutos = (stoi(horaSaida.substr(0, 2)) * 60 + stoi(horaSaida.substr(3, 2))) - (stoi(garagem[i].horaEntrada.substr(0, 2)) * 60 + stoi(garagem[i].horaEntrada.substr(3, 2)));
                    cout << "O veiculo ficou " << totalMinutos << " minutos na garagem.\n";
                    break;
                }
                else
                {
                    cout << "Veiculo nao encontrado \n";
                }
            }

            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);
    return 1;
}
