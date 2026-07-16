#include <iostream>

using namespace std;

int main() {
    float temperaturaCelsius, temperaturaFahrenheit, temperaturaKelvin;

    cout << "Digite a temperatura em Celsius: ";
    cin >> temperaturaCelsius;

    cout << "Escolha a escala para conversão (F para Fahrenheit, K para Kelvin): ";
    char escala;
    cin >> escala;

    switch (escala) {
        case 'F':
        case 'f': // Minusculo e maiusculo para aceitar ambas as entradas
            temperaturaFahrenheit = (temperaturaCelsius * 9 / 5) + 32;
            cout << "Temperatura em Fahrenheit: " << temperaturaFahrenheit << " °F" << endl;
            break;
        case 'K':
        case 'k': // Minusculo e maiusculo para aceitar ambas as entradas
            temperaturaKelvin = temperaturaCelsius + 273.15;
            cout << "Temperatura em Kelvin: " << temperaturaKelvin << " K" << endl;
            break;
        default:
            cout << "Escala inválida. Por favor, escolha F para Fahrenheit ou K para Kelvin." << endl;
    }
    return 0;
}