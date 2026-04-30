#include <iostream>

using namespace std;

int main() {

    long long result = 1;
    int n;

    cout << "Informe o valor de N: " << endl;
    cin >> n;

    while (n > 0) {
        result *= n;
        n -= 1;
        cout << "Fatorial: " << result << endl; 
    }

}

