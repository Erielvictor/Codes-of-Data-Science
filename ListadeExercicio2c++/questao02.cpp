#include <iostream>

using namespace std;

void preencherVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++){
        cout << "Digite o valor para a posição " << i + 1 << ": ";
        cin >> vetor[i];
    }
};

void mostrarvetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main() {
    int tam;
    cout << "Digite o tamanho do vetor: ";
    cin >> tam;

    int vetor[tam];

    preencherVetor(vetor, tam);

    cout << "O vetor digitado é: ";
    
    mostrarvetor(vetor, tam);

    return 0;
}