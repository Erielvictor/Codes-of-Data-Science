#include <iostream>

using namespace std;

int main() {
    float poup_joao = 0.5;
    float poup_maria = 1;
    int anos = 0;

    float investimento_joao = 10000;
    float investimento_maria = 100;

   while (investimento_joao >= investimento_maria) {
        investimento_joao += investimento_joao * poup_joao;
        investimento_maria += investimento_maria * poup_maria;
        anos += 1;
    };

    cout << "Serão necessários " << anos << " anos para que o investimento de Maria ultrapasse o de João." << endl;
}