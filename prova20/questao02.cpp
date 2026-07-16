#include <iostream>

using namespace std;


float calcularSoma(float a, float b) {
    float somaCatetos = (a * a) + (b * b);
    return somaCatetos;
}

bool ehHipotenusa (float h, float a, float b) {

    if (h * h == calcularSoma(a, b)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    float a, b, h;

    cout << "Digite o valor do cateto a: ";
    cin >> a;

    cout << "Digite o valor do cateto b: ";
    cin >> b;

    cout << "Digite o valor da hipotenusa h: ";
    cin >> h;

    if (ehHipotenusa(h, a, b)) {
        cout << "Os valores formam um triangulo retangulo." << endl;
    } else {
        cout << "Os valores nao formam um triangulo retangulo." << endl;
    }
    
    return 0;

}