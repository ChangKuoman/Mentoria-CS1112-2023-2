#include <iostream>
using namespace std;

int main() {

    int a, b;
    char opcion;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;
    cout << "Ingrese la opcion (a, b, c, d):";
    cin >> opcion;

    // logica
    switch (opcion) {
        case 'a':
            cout << "El area del triangulo es: " << a * b / 2.0;
            break;
        case 'b':
            cout << "El promedio de " << a << " y " << b << "es: " << (a + b) / 2.0;
            break;
        case 'c':
            if (b == 0) {
                cout << "No se puede dividir entre 0" << endl;
            }
            else{
                cout << "La division de " << a << " y " << b << "es: " << (a / (double)b);
            }
            break;
        case 'd':
            // operador terciario
            // condicion ? V : F
            cout << "El mayor numero es:" << ((a > b) ? a : b);
            break;
    }

    return 0;
}
