#include <iostream>
#include "funcion.h"
using namespace std;

int main() {
    // declarando las variables
    int a, b, c, d;
    // ingresando los datos
    cout << "Ingrese un numero 1:";
    cin >> a;

    cout << "Ingrese un numero 2:";
    cin >> b;

    cout << "Ingrese un numero 3:";
    cin >> c;

    cout << "Ingrese un numero 4:";
    cin >> d;

    // hallando cantidad de pares
    int cantidad = 0;
    if (es_par(a)) {
        cantidad++;
    }
    if (es_par(b)) {
        cantidad++;
    }
    if (es_par(c)) {
        cantidad++;
    }
    if (es_par(d)) {
        cantidad++;
    }
    // imprimir el resultado
    cout << "Respuesta: ";
    switch (cantidad) {
        case 0:
            cout << "Cero pares" << endl;
            break;
        case 1:
            cout << "Un par" << endl;
            break;
        case 2:
            cout << "Dos pares" << endl;
            break;
        case 3:
            cout << "Tres pares" << endl;
            break;
        case 4:
            cout << "Cuatro pares" << endl;
            break;
    }
    return 0;
}



