#include <iostream>

using namespace std;

void lerVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Digite o valor para a posição " << i + 1 << ": ";
        cin >> vetor[i];
    }
};

void verificarNumero(int vetor[], int tam, int n) {
    bool encontrado = false;

    for (int i = 0; i < tam; i++) {
        if (vetor[i] == n) {
            cout << "O valor existe no vetor no indice " << i << endl;
            encontrado = true;
            break;
        } 
    }

    if (!encontrado) {
        cout << "O valor nao existe no vetor" << endl;
    }
}

void imprimirVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
}

int main() {
    int tam;
    cout << "Informe o tamanho do seu vetor: ";
    cin >> tam;

    int vetor[tam];

    lerVetor(vetor, tam);
    imprimirVetor(vetor, tam);

    int n;
    cout << "Qual numero você quer encontrar? " << endl;
    cin >> n;

    verificarNumero(vetor, tam, n);

    return 0;

}