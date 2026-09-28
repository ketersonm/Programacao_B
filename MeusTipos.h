typedef struct{
   string nome;
    int idade;
    float altura;
    float peso;
} IndiceMassaCorporal

void popularVetor(int vetor[], int tamanho) {
    //rotina ou uma funcionalidade para popular o vetor com TAM numeros aleatórios
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibirVetor(int vetor[], int tamanho) {
    //rotina ou uma funcionalidade para exibir o vetor com TAM numeros aleatorios
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << endl;
    }
}
