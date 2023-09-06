#include <iostream>
#include <cmath>
//#include <math.h>
using namespace std;

void ejercicio1() {
    for (int i=100; i>=0; i-=10) {
        int resultado = i * 9/5 + 32;
        cout << "La temperatura es " << i << " C, " << resultado << " F" << endl;
    }

    int c = 100;
    while (c >= 0) {
        int f = c * 9/5 + 32;
        cout << "La temperatura es " << c << " C, " << f << " F" << endl;
        c -= 10;
    }
}

void ejercicio2() {
    int n;
    cout << "Ingrese el valor de N: ";
    cin >> n;

    int resultado = 0;
    for (int i=1; i<=n; i++) {
        resultado += pow(i, 5);
    }
    cout << resultado << endl;
}

void ejercicio3() {
    int cant_votantes;
    cout << "Ingrese numero de votantes:";
    cin >> cant_votantes;

    int a = 0, b = 0, c = 0;

    for (int i=0; i<cant_votantes; i++){
        char candidato;
        cout << "Por quien vota?:";
        cin >> candidato;
        string clan;
        cout << "Clan?:";
        cin >> clan;

        int voto = 1;
        if (clan == "toriente") {
            voto *= 2;
        }
        else if (clan == "folunta") {
            voto *= 3;
        }

        switch (candidato) {
            case 'A':
                a += voto;
                break;
            case 'B':
                b += voto;
                break;
            case 'C':
                c += voto;
                break;
        }
    }
    cout << "Ganador: ";
    if (a > b and a > c) {
        cout << "A" << endl;
    }
    else if (b > a and b > c) {
        cout << "B" << endl;
    }
    else {
        cout << "C" << endl;
    }
}

void ejercicio4() {
    string input;
    cout << "Input:";
    getline(cin, input);

    string output;

    for (int i = 0; i < input.size(); i++) {
        if (input[i + 1] == ' ' && i + 1 < input.size()) {
            output += toupper(input[i]);
        }
        else if (i == input.size() - 1) {
            output += toupper(input[i]);
        }
        else {
            output += tolower(input[i]);
        }
    }

    cout << "Output: " << output << endl;

}

void ejercicio5() {
    int n;
    do {
        cout << "N (5 < N < 10):";
        cin >> n;
    } while (n < 5 || n > 10);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (
                    i == 0
                    || j == 0
                    || i == n - 1
                    || j == n - 1
                    || i == j
                    || i + j == n - 1) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void ejercicio6() {
    int n;
    do {
        cout << "N (>=3):";
        cin >> n;
    } while (n < 3);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                cout << "* ";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void ejercicio7() {
    int n;
    cout << "Ingrese el numero:";
    cin >> n;

    for (int i=1; i <= n; i++) {
        for (int j=1; j <= 9; j++) {
            cout << i << "*" << j << " = " << i*j << endl;
        }
        cout << endl;
    }
}

void ejercicio8() {
    int n;
    do {
        cout << "N (>=1):";
        cin >> n;
    } while (n < 1);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (
                    i == 0
                    || j == 0
                    || i == n - 1
                    || j == n - 1) {
                cout << i + 1 << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void ejercicio9() {
    int n;
    do {
        cout << "N (>=1):";
        cin >> n;
    } while (n < 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                cout << ((i + j) % 2 == 0 ? '1' : '0') << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void ejercicio10() {
    int n;
    cout << "Ingrese un numero:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < n; j++) {
            if (i == j || j == 0 || i == n - 1) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void ejercicio11() {
    int n;
    cout << "Ingrese un numero:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                cout << ((i + j) % 2 == 0 ? "*" : " ") << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void ejercicio12() {
    int n;
    cout << "Ingrese un numero:";
    cin >> n;

    for (int i = 1; i < n; i++) {
        cout << "  ";
    }
    cout << 1 << endl;

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << "  ";

        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void ejercicio13() {
    int n;
    do {
        cout << "numero (>= 11):";
        cin >> n;
    } while (n < 11);

    for (int i = 11; i <= n; i++){
        bool es_igual = true;
        int temporal = i;

        int primer_digito = temporal % 10;

        while (temporal >= 10) {
            temporal = temporal / 10;
            int n_digito = temporal % 10;

            if (n_digito != primer_digito) {
                es_igual = false;
            }
        }
        if (es_igual) {
            cout << i << endl;
        }
    }
}

int main() {
//    ejercicio1();

    return 0;
}
