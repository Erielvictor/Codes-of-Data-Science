#include <iostream>

#include <cstdlib> // Necessária para rand() e srand()
#include <ctime>   // Necessária para time()

using namespace std;

void montarMatriz(int matriz[10][10]) { // declara o tamanho da matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "Digite o valor para a posição [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }
}

int maiorValor(int matriz[10][10]) {
    int maior = matriz[0][0]; // Inicializa o maior valor com o primeiro elemento da matriz
    int linhaMaior = 0;
    int colunaMaior = 0;


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matriz[i][j] > maior) { // Compara cada elemento com o maior valor atual
                maior = matriz[i][j]; // Atualiza o maior valor se encontrar um valor maior
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    cout << "O maior valor está na posição [" << linhaMaior + 1 << "][" << colunaMaior + 1 << "]" << endl; // Exibe a posição do maior valor encontrado

    cout << "A linha do maior valor é: ";
    for (int j = 0; j < 10; j++) {
        cout << matriz[linhaMaior][j] << " "; // Exibe a linha do maior valor encontrado
    }
    cout << endl;
    
    cout << "A coluna do maior valor é: ";
    for (int j = 0; j < 10; j++) {
        cout << matriz[j][colunaMaior] << " "; // Exibe a coluna do maior valor encontrado
    }
    cout << endl;

    return maior; // Retorna o maior valor encontrado na matriz
}

int gerarMatrizAleatoria(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = (rand() % 100) + 1; // Gera um número aleatório entre 1 e 100
        }
    }
}

int main() {
    srand(time(0)); // Inicializa a semente para geração de números aleatórios
    int numeroaAleatorio = (rand() % 100) + 1; // Gera um número aleatório entre 0 e 99

    int matriz[10][10]; //Reserva espaço para uma matriz 10x10

    // montarMatriz(matriz);
    gerarMatrizAleatoria(matriz);

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