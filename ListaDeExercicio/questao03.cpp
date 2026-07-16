#include <iostream>

using namespace std;

int main() {

    float soma = 0;
    float media = 0;
    int valores;
    int contador = 0;


    while (contador <= 19){

        cout << "Informe os valores: " << endl;
        cin >> valores;

        contador += 1;
        soma += valores;


    };

    media = soma / 20;

    cout << "A media dos 20 valores e: " << media << endl;

    return 0;
}