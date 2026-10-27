#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;


typedef struct {
    string local;
    float nota;
} foto;

bool inserir(vector<foto>& fotos) {
    foto fotoTMP;

    cout << "Digite o lugar: ";
    getline(cin, fotoTMP.local);

    if (fotoTMP.local.empty()) {
        cout << "O nome do lugar nao pode ser vazio.\n";
        return false;
    }

    // Verifica se o lugar já existe no vetor
    for (int i = 0; i < fotos.size(); i++) {
        if (fotoTMP.local == fotos[i].local) {
            cout << "Foto ja cadastrada na estrutura.\n";
            return false;
        }
    }

    cout << "Digite a nota: ";
    while (!(cin >> fotoTMP.nota)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nota invalida. Digite um numero para a nota: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    fotos.push_back(fotoTMP);
    cout << "Foto inserida com sucesso.\n";
    return true;
}

void listar(vector<foto> fotos) {
    if (fotos.empty()) {
        cout << "Nenhuma foto cadastrada.\n";
        return;
    }

    cout << "\nFotos cadastradas:\n";
    for (int i = 0; i < fotos.size(); i++) {
        cout << i + 1 << " - Lugar: " << fotos[i].local << "  Nota: " << fotos[i].nota << "\n";
    }
}

void pesquisar(const vector<foto>& fotos) {
    string termoBusca;

    cout << "Digite o lugar que deseja pesquisar: ";
    getline(cin, termoBusca);

    bool encontrado = false;
    for (size_t i = 0; i < fotos.size(); i++) {
        if (termoBusca == fotos[i].local) {
            cout << "Foto encontrada! Lugar: " << fotos[i].local << " | Nota: " << fotos[i].nota << "\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Foto nao encontrada.\n";
    }
}

bool remover(vector<foto>& fotos) {
    string termoBusca;

    cout << "Digite o lugar da foto que deseja remover: ";
    getline(cin, termoBusca);

    for (auto it = fotos.begin(); it != fotos.end(); ++it) {
        if (it->local == termoBusca) {
            fotos.erase(it);
            cout << "Foto removida com sucesso.\n";
            return true;
        }
    }

    cout << "Foto nao encontrada.\n";
    return false;
}

void carregarBase(string FotoBase, vector<foto>& fotos) {
    ifstream arquivo(FotoBase);

    if (!arquivo) {
        return;
    }

    string local;
    string notaStr;

    // Le o arquivo separando pelo caractere ';'
    while (getline(arquivo, local, ';') && getline(arquivo, notaStr)) {
        if (!local.empty() && !notaStr.empty()) {
            foto f;
            f.local = local;
            f.nota = stof(notaStr);
            fotos.push_back(f);
        }
    }

    arquivo.close();
}

void atualizarBase(const vector<foto>& fotos, string FotoBase) {
    ofstream arquivo(FotoBase);

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para gravacao.\n";
        return;
    }

    // Grava no arquivo no formato: local;nota
    for (size_t i = 0; i < fotos.size(); i++) {
        arquivo << fotos[i].local << ";" << fotos[i].nota << "\n";
    }

    arquivo.close();
}

void ordenar(vector<foto>& fotos) {
    // Bubble sort ordenando pelo campo 'local'
    foto tmp;
    bool houveTroca;

    if (fotos.empty()) return;

    do {
        houveTroca = false;
        for (size_t i = 0; i < fotos.size() - 1; i++) {
            if (fotos[i].local > fotos[i + 1].local) {
                houveTroca = true;
                tmp = fotos[i];
                fotos[i] = fotos[i + 1];
                fotos[i + 1] = tmp;
            }
        }
    } while (houveTroca);
}

int main() {
    vector<foto> fotos;
    int opcao;
    string FotoBase = "fotos.txt";

    // Carregar a base de dados para a estrutura fotos
    carregarBase(FotoBase, fotos);

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir lugar\n";
        cout << "2 - Listar fotos\n";
        cout << "3 - Pesquisar fotos por lugares\n";
        cout << "4 - Remover foto\n";
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
                    // ordenar o vetor
                    ordenar(fotos);
                    // atualizar base de dados
                    atualizarBase(fotos, FotoBase);
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
                    // atualizar base de dados
                    atualizarBase(fotos, FotoBase);
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