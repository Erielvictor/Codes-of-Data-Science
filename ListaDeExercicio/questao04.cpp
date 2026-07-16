#include <iostream>

using namespace std;

int main() {

    int quant = 0;
    float soma = 0;
    int contador = 0;
    int numero = 0;
    

    cout << "Quantos numeros voce quer informar? " << endl;
    cin >> quant;

    while (contador <= quant - 1 ) {
        contador += 1;

        cout << "Informe o numero a ser adicionado: " << endl;
        cin >> numero;

        if (numero % 2 == 0) {
            soma += numero;
        };

    };

    cout << "A soma dos valores pares é: " << soma << endl;
    
    return 0;
}