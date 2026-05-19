#include <iostream>

using namespace std;

void preencherVetor (int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Digite o valor para a posição " << i + 1 << ": ";
        cin >> vetor[i];
    }
}

void dividirVetor (int vetorOriginal[], int vetor1[], int vetor2[], int tamTotal) {
    int metade = tamTotal / 2;

    for (int i = 0; i < metade; i++) {
        vetor1[i] = vetorOriginal[i];
    }

    for (int i = metade; i < tamTotal; i++) {
        vetor2[i - metade] = vetorOriginal[i]; // usar i - metade garante que o índice de v2 comece do 0
    }
}

void mostrarVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
}

int main() {
    int tam;
    cout << "Digite o tamanho do vetor (deve ser par): ";
    cin >> tam;

    int vetorOriginal[tam];

    int tamTotal = tam;
    int vetor1[tamTotal / 2];
    int vetor2[tamTotal - tamTotal / 2];

    preencherVetor(vetorOriginal, tamTotal);
    
    dividirVetor(vetorOriginal, vetor1, vetor2, tamTotal);

    mostrarVetor(vetor1, tamTotal / 2);
    cout << endl;
    mostrarVetor(vetor2, tamTotal - tamTotal / 2);
    cout << endl;

    return 0;
}