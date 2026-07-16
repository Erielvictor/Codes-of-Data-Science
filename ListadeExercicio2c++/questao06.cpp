#include <iostream>

using namespace std;

bool verificarNumeros(int n) {
    if (n % 2 == 0) {
        cout << n << " é par." << endl;
        return false;
    }
    else {
        cout << n << " é impar." << endl;
        return true;
    }
}

int contarImpares(int matriz[10][10]) {
    int contador = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (verificarNumeros(matriz[i][j])) { 
                contador++;
            }
        }
    }
    return contador;
}

void preencherMatriz(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "Digite o valor para a posição [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }
    
}



int main() {

    int matriz[10][10];

    preencherMatriz(matriz);

    int totalImpares = contarImpares(matriz);
    cout << "Total de números ímpares: " << totalImpares << endl;

    return 0;
}