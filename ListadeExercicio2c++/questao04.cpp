#include <iostream>

using namespace std;

void preencherVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Digite o valor para a posição " << i + 1 << ": ";
        cin >> vetor[i];
    }
}

bool verificarPrimos (int n) {
    if (n <= 1) {
        cout << n << " não é primo." << endl;
        return false;
    }

    for (int i = 2; i < n; i++) { 
        if (n % i == 0 ) { 
            return false; 
        }
    }
    return true; 
}

int contarPrimos(int vetor[], int tam) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (verificarPrimos(vetor[i])) {
            cout << vetor[i] << " é primo." << endl;
            contador++;
        }
    }
    return contador;
}

int main() {
    int tam;
    cout << "Digite o tamanho do vetor: ";
    cin >> tam;

    int vetor[tam];

    preencherVetor(vetor, tam);
    int totalPrimos = contarPrimos(vetor, tam);
    cout << "Total de números primos: " << totalPrimos << endl;

    return 0;
}