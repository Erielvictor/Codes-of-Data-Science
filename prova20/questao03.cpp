#include <iostream>

using namespace std;


void verificarletra(char Letra) {
    switch (Letra) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "A letra e uma vogal." << endl;
            break;
        default:
            cout << "A letra e uma consoante." << endl;
    }
}

int main() {
    char letra;
    cout << "Informe uma letra: ";
    cin >> letra;

    letra = tolower(letra);

    verificarletra(letra);


    return 0;
}