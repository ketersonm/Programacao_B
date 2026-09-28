#include <iostream>
#include <string>
#include <vector>
using namespace std;

 string nome1, nome2;

int main (){
    cout << "Digite o primeiro nome: ";
    getline(cin, nome1);
    cout << "Digite o segundo nome: ";
    getline(cin, nome2);
    cout << "O primeiro nome eh: " << nome1 << endl;
    return 0;
}