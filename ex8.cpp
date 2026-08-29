#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "meusTipos.h"

int main()
{

    vector<imovel> casas;

    int opcao;
    int somaConsumo = 0;
    float media;

    do {
    
        cout << "Menu de Opcoes:" << endl;
        cout << "1. Adicionar imovel" << endl;
        cout << "2. Calcular media de consumo" << endl;
        cout << "3. Listar imoveis" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                imovel imovelTMP;
                cout << "Digite o numero da casa: ";
                cin >> imovelTMP.casa;
                cout << "Digite o consumo em kwh: ";
                cin >> imovelTMP.consumo;
                casas.push_back(imovelTMP);
                break;
            
            case 2: 
                if (casas.empty()) {
                    cout << "Nenhum imovel cadastrado." << endl;
                    break;
                }
    
                for (int i = 0; i < casas.size(); i++) {
                    somaConsumo += casas[i].consumo;
                }
                media = somaConsumo / casas.size();
                cout << "Media de consumo: " << media << endl;
                break;
            
            case 3: 
                if (casas.empty()) {
                    cout << "Nenhum imovel cadastrado." << endl;
                    break;
                }
                for (int i = 0; i < casas.size(); i++) {
                    if (casas[i].consumo > media) {
                        cout << "Casa: " << casas[i].casa << ", Consumo: " << casas[i].consumo << endl;
                    }
                }
                break;
            
            case 4:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while(opcao != 4);        

    return 1;
}
