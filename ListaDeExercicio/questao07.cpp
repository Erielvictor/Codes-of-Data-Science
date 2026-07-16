#include <iostream>

using namespace std;

int main() {
    int totalNumeros, numero;
    int pares = 0;
    int impares = 0;
    int i = 0;

    cout << "Digite a quantidade de números que deseja inserir: ";
    cin >> totalNumeros;

    while (i < totalNumeros) {
        cout << "Digite o número " << (i + 1) << ": ";
        cin >> numero;

        if (numero % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
        i++;
    }

    cout << "Quantidade de números pares: " << pares << endl;
    cout << "Quantidade de números ímpares: " << impares << endl;

    return 0;
}