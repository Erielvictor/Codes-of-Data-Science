#include <iostream>

using namespace std;

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

void classificarIMC(float imc) {
    if (imc > 25.0) {
        cout << "Esta acima do peso." << endl;
    } else if (imc >= 18.5) {
        cout << "Esta com o peso ideal." << endl;
    } else {
        cout << "Esta abaixo do peso." << endl;
    }
}

int main() {
    float peso, altura;

    cout << "Digite o peso (em kg): ";
    cin >> peso;

    cout << "Digite a altura (em metros): ";
    cin >> altura;

    float imc = calcularIMC(peso, altura);
    cout << "O IMC calculado é: " << imc << endl;

    classificarIMC(imc);

    return 0;
}