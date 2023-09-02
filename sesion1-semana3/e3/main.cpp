#include <iostream>
using namespace std;

int main() {

    int a1, a2, a3;
    cout << "angulo 1:";
    cin >> a1;
    cout << "angulo 2:";
    cin >> a2;
    cout << "angulo 3:";
    cin >> a3;

    if (a1 == 90 or a2 == 90 or a3 == 90) {
        cout << "Si es un triangulo rectangulo" << endl;
    }
    else {
        cout << "No es un triangulo rectangulo" << endl;
    }
    return 0;
}
