#include <iostream>

using namespace std;

void somandoMatrizes(int matriz1[2][2], int matriz2[2][2], int resultado[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j]; 
        }
    }
}

int main() {
    int matriz1[2][2];
    int matriz2[2][2];
    int resultado[2][2];

    cout << "Digite os valores para a primeira matriz (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Digite os valores para a segunda matriz (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }

    somandoMatrizes(matriz1, matriz2, resultado);
    cout << "Resultado da soma das matrizes:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << resultado[i][j] << " "; // Exibe o resultado da soma das matrizes
        }
        cout << endl;
    }

    return 0;
}