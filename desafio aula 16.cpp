#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

#include "meusTipos.h"

int main(){
    vector<Degustacao> degustacoes;
    string BaseDados = "baseDados.csv";
    int opcao;
    Degustacao DegustacaoTMP;
    string procura;
    string linha;
    auto limparBuffer = []() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    ofstream procuradorArquivo;
   

    do {
        cout << "MENU DE DEGUSTACOES" << endl;
        cout << "1. Cadastrar degustacao" << endl;
        cout << "2. Listar degustacoes" << endl;
        cout << "3. Remover degustacao" << endl;
        cout << "4. Pesquisar degustacao" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        limparBuffer();

        switch (opcao) {
            case 1: {
                procuradorArquivo.open(BaseDados, ios::app);

                cout << "Diga a data da degustacao: ";
                getline(cin, DegustacaoTMP.dataDegustacao);
                cout << "Diga o nome do que comeu: ";
                getline(cin, DegustacaoTMP.nomeAlimento);
                cout << "Diga a nota: ";
                cin >> DegustacaoTMP.nota;
                limparBuffer();
                cout << "Diga o fabricante: ";
                getline(cin, DegustacaoTMP.fabricante);
                cout << "Diga o comentario: ";
                getline(cin, DegustacaoTMP.comentario);
                procuradorArquivo << DegustacaoTMP.dataDegustacao << ";"
                 << DegustacaoTMP.nomeAlimento << ";"
                 << DegustacaoTMP.nota << ";"
                 << DegustacaoTMP.fabricante << ";"
                 << DegustacaoTMP.comentario << endl;
                degustacoes.push_back(DegustacaoTMP);
                cout << "Degustacao cadastrada com sucesso!" << endl;
                break;
            }
            case 2: {
                 ifstream leitorArquivo;
                leitorArquivo.open(BaseDados);

                if (leitorArquivo.is_open()) {
                    string linha;
                    while (getline(leitorArquivo, linha)) {
                        cout << linha << endl;
                    }
                } else {
                    cout << "Erro ao abrir o arquivo." << endl;
                }
                leitorArquivo.close();
                break;
            }
            case 3: {
                if (degustacoes.empty()) {
                    cout << "Nenhuma degustacao cadastrada." << endl;
                } else {
                    int indice;
                    cout << "Digite o indice da degustacao a ser removida: ";
                    cin >> indice;
                    limparBuffer();
                    if (indice >= 0 && indice < degustacoes.size()) {
                        linha.erase(linha.begin() + indice);
                        cout << "Degustacao removida com sucesso!" << endl;
                    } else {
                        cout << "Indice inválido." << endl;
                    }
                }
                break;
            }
            case 4: {
                cout << "Digite o nome do alimento a ser pesquisado: ";
                getline(cin, procura);
                cout << "Resultados da pesquisa:" << endl;
                for (int i = 0; i < degustacoes.size(); i++) {
                    if (degustacoes[i].nomeAlimento == procura) {
                        cout << "Data: " << degustacoes[i].dataDegustacao << endl;
                        cout << "Nome do alimento: " << degustacoes[i].nomeAlimento << endl;
                        cout << "Nota: " << degustacoes[i].nota << endl;
                        cout << "Fabricante: " << degustacoes[i].fabricante << endl;
                        cout << "Comentario: " << degustacoes[i].comentario << endl;
                    }
                }
                break;
            }
            case 5: {
                cout << "Saindo do programa." << endl;
                break;
            }
            default: {
                cout << "Opcao inválida. Tente novamente." << endl;
            }
        }

    } while (opcao != 5);

    procuradorArquivo.close();
 

    return 0;
}