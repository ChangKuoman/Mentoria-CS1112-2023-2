#include <iostream>
using namespace std;


int main() {
    float p1, p2, p3;

    cout << "Ingrese el valor del primer producto:";
    cin >> p1;
    while (p1 <= 0) {
        cout << "Por favor ingrese un precio correcto para el primer producto:";
        cin >> p1;
    }

    cout << "Ingrese el valor del segundo producto:";
    cin >> p2;
    while (p2 <= 0) {
        cout << "Por favor ingrese un precio correcto para el segundo producto:";
        cin >> p2;
    }

    cout << "Ingrese el valor del tercer producto:";
    cin >> p3;
    while (p3 <= 0) {
        cout << "Por favor ingrese un precio correcto para el tercer producto:";
        cin >> p3;
    }

    // logica


    if (p1 + p2 + p3 >= 500) {
        cout << "El precio total es (aplica descuento):" << (p1 + p2 + p3) * 0.85;
    }
    else if (p1 + p2 + p3 >= 200) {
        cout << "El precio total es (aplica descuento):" << (p1 + p2 + p3) * 0.95;
    }
    else {
        cout << "El total es (no aplica descuento) " << (p1 + p2 + p3);
    }
    return 0;
}
