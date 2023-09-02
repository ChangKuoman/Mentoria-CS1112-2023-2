#include <iostream>
using namespace std;

int main() {
    int edad;
    string clan;

    cout << "Ingrese su edad:";
    cin >> edad;

    cout << "Ingrese su clan:";
    cin >> clan;

    // logica
    if (edad >= 15) {
        if (clan == "pretino") {
            // 500
            cout << "Te corresponde un bono de 500 estufares" << endl;
        }
        else if (clan == "folunta") {
            // 700
            cout << "Te corresponde un bono de 700 estufares" << endl;
        }
        else if (clan == "toriente") {
            // 600
            cout << "Te corresponde un bono de 600 estufares" << endl;
        }
    }
    else { // edad < 15
        cout << "No te corresponde el bono" << endl;
    }


    return 0;
}
