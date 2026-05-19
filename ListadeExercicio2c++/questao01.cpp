#include <iostream>

using namespace std;

int main() {
    int vetor[30];
    int pares = 0;
    for (int i = 0; i < 30; i++) {
        cout << "Digite o valor do elemento " << i + 1 << ": ";
        cin >> vetor[i];
    };

    for (int i = 0; i < 30; i++) {
        if (vetor[i] % 2 == 0) {
            cout << "O elemento " << i  << " é par: " << vetor[i] << endl;
            pares ++;
        }
        else {
            cout << "O elemento " << i + 1 << " é impar: " << vetor[i] << endl;
        }
    }

    cout << "A quantidade de números pares é: " << pares << endl;

    return 0;
}

