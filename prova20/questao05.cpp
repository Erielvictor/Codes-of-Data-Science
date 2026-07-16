#include <iostream>

using namespace std;

const int MAX = 10;

void povoarMatriz(int matriz[MAX][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Digite o valor para [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void gerarTransposta(int original[MAX][MAX], int transposta[MAX][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = original[i][j];
        }
    }
}

void imprimirMatriz(int matriz[MAX][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrizOriginal[MAX][MAX];
    int matrizTransposta[MAX][MAX];
    int l, c;

    cout << "Digite a quantidade de linhas: ";
    cin >> l;
    cout << "Digite a quantidade de colunas: ";
    cin >> c;

    if (l > MAX || c > MAX || l <= 0 || c <= 0) {
        cout << "Nao eh possivel realizar a operacao. Tamanho invalido ou excede o limite." << endl;
        return 0;
    }

    povoarMatriz(matrizOriginal, l, c);
    gerarTransposta(matrizOriginal, matrizTransposta, l, c);

    cout << "Matriz original" << endl;
    imprimirMatriz(matrizOriginal, l, c);

    cout << "Matriz transposta" << endl;
    imprimirMatriz(matrizTransposta, c, l);

    return 0;
}