#include <iostream>
#include <string>

using namespace std;
string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}
int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);
    frase = paraMaiusculo(frase);
    cout << "A frase em maiúscula eh: " << frase << endl;
    return 0;
}