#include <iostream>
#include <fstream> // Biblioteca necessária para manipulação de arquivos
#include <string>
#include <vector>

using namespace std;

// Alterado para retornar um vector<string> em vez de um ponteiro alocado manualmente
vector<string> split(string frase, string delimitador = " ")
{
    vector<string> resultado; // Gerenciamento automático de memória
    int inicio = 0;
    int fim = frase.find(delimitador);
    
    while (fim != -1) {
        resultado.push_back(frase.substr(inicio, fim - inicio));
        inicio = fim + delimitador.size();
        fim = frase.find(delimitador, inicio);
    }
    resultado.push_back(frase.substr(inicio, fim - inicio));

    return resultado;
}

typedef struct {
    string mes;
    float valor;
} Inflacao;

int main() {
    vector<Inflacao> vetorInflacao;
    Inflacao tmp;

    // 1. Abre o arquivo para leitura
    ifstream arquivo("inflacao.csv");

    // 2. Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 0;
    }

    string linha;
    
    // 3. Lê o arquivo linha por linha até o fim
    while (getline(arquivo, linha)) {
        //fazer split da linha e pegar mes e valor
        vector<string> vetorPalavras = split(linha, ",");

        tmp.mes = vetorPalavras[0];
        tmp.valor = stof(vetorPalavras[1]);

        // cout << tmp.mes << "   " << tmp.valor << endl;

        vetorInflacao.push_back(tmp);
    }

    // 4. Fecha o arquivo (boa prática)
    arquivo.close();

    //5. Exibe o vetor de nomes
    for (int i = 0; i < vetorInflacao.size(); i++) {
        cout << "Mes: " << vetorInflacao[i].mes << " | Inflacao: " << vetorInflacao[i].valor << endl;
    }

    return 0;
}
