#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "meusTipos.h"

int main(){

    int opcao;
    vector<Game> jogador;
    Game jogadorTMP;

    do{
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - Cadastrar jogador" << endl;
        cout << "2 - Listar jogadores" << endl;
        cout << "3 - Buscar jogador" << endl;
        cout << "4 - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1: 
                cout << "Digite o ID do jogador: ";
                cin >> jogadorTMP.id;
                cout << "Digite a pontuacao do jogador: ";
                cin >> jogadorTMP.pontuacao;
                jogador.push_back(jogadorTMP);
                break;

            case 2:
            if(jogador.empty()){
                cout << "Nenhum jogador cadastrado!" << endl;
            } else {
                cout << "Lista de jogadores: " << endl;
                for(int i = 0; i < jogador.size(); i++){
                    cout << "ID: " << jogador[i].id << ", Pontuacao: " << jogador[i].pontuacao << endl;
                }
            }
                break;
            case 3: 
                cout << "Digite o ID do jogador que deseja buscar: ";
                cin >> jogadorTMP.id;
                for(int i = 0; i < jogador.size(); i++){
                    if(jogador[i].id == jogadorTMP.id){
                        cout << "Jogador encontrado: ID: " << jogador[i].id << ", Pontuacao: " << jogador[i].pontuacao << endl;
                        break;
                    }
                    if(i == jogador.size() - 1){
                        cout << "Jogador nao encontrado!" << endl;
                    }
                }
            case 4: 
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }
        
    } while(opcao != 4);
    return 1;
}
