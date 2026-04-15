#include <iostream>

using namespace std;

int main() {
    float notaProva, notaTrabalho, media;

    int pesoProva = 7;
    int pesoTrabalho = 3;

    // 2. Pedir e ler a nota da prova
    cout << "Informe a nota da prova: " << endl;
    cin >> notaProva;

    // 3. Pedir e ler a nota do trabalho
    cout << "Informe a nota do Trabalho: " << endl;
    cin >> notaTrabalho;

    // 4. Calcular a média ponderada
    media = ((notaProva * pesoProva) + (notaTrabalho * pesoTrabalho)) / (pesoProva + pesoTrabalho);
    // 5. Mostrar o resultado

    cout << "A Media do aluno é: "<< media << endl;
    
    return 0;
}