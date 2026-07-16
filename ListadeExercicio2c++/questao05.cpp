#include <iostream>

using namespace std;

void montarMatriz(int matriz[10][10]) { 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "Digite o valor para a posição [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }
}

int maiorValor(int matriz[10][10]) {
    int maior = matriz[0][0]; 
    int linhaMaior = 0;
    int colunaMaior = 0;


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matriz[i][j] > maior) { 
                maior = matriz[i][j]; 
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    cout << "O maior valor está na posição [" << linhaMaior + 1 << "][" << colunaMaior + 1 << "]" << endl; 

    cout << "A linha do maior valor é: ";
    for (int j = 0; j < 10; j++) {
        cout << matriz[linhaMaior][j] << " "; 
    }
    cout << endl;
    
    cout << "A coluna do maior valor é: ";
    for (int j = 0; j < 10; j++) {
        cout << matriz[j][colunaMaior] << " "; 
    }
    cout << endl;

    return maior; 
}

int main() {


    int matriz[10][10]; 

    montarMatriz(matriz);


    cout << "A matriz digitada é: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "O maior valor da matriz é: " << maiorValor(matriz) << endl;

    return 0;
}