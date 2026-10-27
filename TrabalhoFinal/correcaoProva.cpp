#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;


typedef struct{
   string local;
    int nota;
    
} fotos;


bool inserir(vector<string>& fotos) {
    string nome;

    cout << "Digite o nome: ";
    getline(cin, nome);

    if (nome.empty()) {
        cout << "O nome nao pode ser vazio.\n";
        return false;
    }

    bool encontrado = false;
    for (int i = 0; i < fotos.size(); i++) {
        if (nome == fotos[i]) {
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        cout << "Nome ja cadastrado na estrutura.\n";
        return false;
    } else {
        fotos.push_back(nome);
        cout << "Nome inserido com sucesso.\n";
        return true;
    } 
}

void listar(vector<string> fotos) {
    if (fotos.empty()) {
        cout << "Nenhum nome cadastrado.\n";
        return;
    }

    cout << "\nNomes cadastrados:\n";
    for (int i = 0; i < fotos.size(); i++) {
        if (!fotos[i].empty()) {
            cout << i + 1 << " - " << fotos[i] << "\n";
        }
    }
}

void pesquisar(vector<string> fotos) {
    string nome;

    cout << "Digite o nome que deseja pesquisar: ";
    getline(cin, nome);

    // vector<string>::const_iterator encontrado =
    //     find(fotos.begin(), fotos.end(), nome);

    // if (encontrado != fotos.end()) {
    //     cout << "Nome encontrado.\n";
    // } else {
    //     cout << "Nome nao encontrado.\n";
    // }

    bool encontrado = false;
    for (int i = 0; i < fotos.size(); i++) {
        if (nome == fotos[i]) {
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        cout << "Nome encontrado.\n";
    } else {
        cout << "Nome nao encontrado.\n";
    }
}

bool remover(vector<string>& fotos) {
    string nome;

    cout << "Digite o nome que deseja remover: ";
    getline(cin, nome);

    vector<string>::iterator encontrado =
        find(fotos.begin(), fotos.end(), nome);

    if (encontrado != fotos.end()) {
        fotos.erase(encontrado);
        cout << "Nome removido com sucesso.\n";
        return true;
    } else {
        cout << "Nome nao encontrado.\n";
        return false;
    }
}

void carregarBase(string nomeBase, vector<string>& fotos) {
    ifstream arquivo;
    arquivo.open(nomeBase);

    if (!arquivo) {
        return;
    } 
 
	//le o arquivo capturando as frases
	string linha;
	while (!arquivo.eof()) {
		getline(arquivo,linha); //lendo a linha inteira
		fotos.push_back(linha);
	}
    arquivo.close();
}

void atualizarBase(vector<string> fotos, string nomeBase) {
    ofstream arquivo;
    arquivo.open(nomeBase);

    for (int i = 0; i < fotos.size(); i++) {
        arquivo << fotos[i] << endl;
    }

    arquivo.close();
}

void ordenar(vector<string>& fotos) {
    //usando o bubble sort ou bolha
    string tmp;
    bool houveTroca;
    do {
        houveTroca = false;
        for (int i = 0; i < fotos.size()-1; i++) {
            if (fotos[i] > fotos[i+1]) {
                houveTroca = true;
                tmp = fotos[i];
                fotos[i] = fotos[i+1];
                fotos[i+1] = tmp;
            }
        }
    } while (houveTroca);
}

int main() {
    vector<string> fotos;
    int opcao;
    string nomeBase = "fotos.txt";

    //carregar a base de dados para a estrutura fotos
    carregarBase(nomeBase, fotos);

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir nome\n";
        cout << "2 - Listar fotos\n";
        cout << "3 - Pesquisar nome\n";
        cout << "4 - Remover nome\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Digite um numero entre 1 e 5.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                if (inserir(fotos)) {
                    //ordenar o vetor
                    ordenar(fotos);
                    //atualizar base de dados
                    atualizarBase(fotos, nomeBase);
                }
                break;
            case 2:
                listar(fotos);
                break;
            case 3:
                pesquisar(fotos);
                break;
            case 4:
                if (remover(fotos)) {
                    //atualizar base de dados
                    atualizarBase(fotos, nomeBase);
                }
                break;
            case 5:
                cout << "Programa encerrado.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 5);

    return 0;
}