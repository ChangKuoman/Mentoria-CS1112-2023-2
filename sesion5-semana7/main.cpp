#include <iostream>
#include <vector>
using namespace std;

void e1() {
    int m1, m2, b1, b2;
    cout << "m1:";
    cin >> m1;
    cout << "m2:";
    cin >> m2;
    cout << "b1:";
    cin >> b1;
    cout << "b2:";
    cin >> b2;

    double y, y1, y2, x2, x1, x = 0;

    while (true) {
        if (m1 > m2) {
            y = m1 * x + b1;
            y2 = m2 * x + b2;
            if (y2 - y < 0.001) {
                break;
            }
            x1 = (y2 - b1) / m1;
            if (x1 - x < 0.001) {
                break;
            }
            x = x1;
        } else {
            y = m2 * x + b2;
            y1 = m1 * x + b1;
            if (y2 - y < 0.001) {
                break;
            }
            x2 = (y1 - b2) / m2;
            if (x2 - x < 0.001) {
                break;
            }
            x = x2;
        }
    }
    cout << x << " " << y << endl;

}

bool esta_en(int i, int j, double expectativa_vida[6], double tasa_mortalidad_infantil[6]) {
    for (int k = 0; k < 6; k++) {
//        cout << int(expectativa_vida[k] / 10) << " " << int(tasa_mortalidad_infantil[k]) << endl;
        if (
                int(*(expectativa_vida + k) / 10) == i
                and
                int(*(tasa_mortalidad_infantil + k)) == j
                ) {
            return true;
        }
    }
    return false;
}

int esta_pos(int i, int j, double expectativa_vida[6], double tasa_mortalidad_infantil[6]) {
    for (int k = 0; k < 6; k++) {
        if (
                int(expectativa_vida[k] / 10) == i
                and
                int(tasa_mortalidad_infantil[k]) == j
                ) {
            return k;
        }
    }
}

void e2() {
    char pais[6] = { 'L', 'C', 'N', 'J', 'S', 'P'};
    double expectativa_vida[6] = {54.29, 54.99, 54.69, 84.63, 83.78, 81.92};
    double tasa_mortalidad_infantil[6] = {7.176, 9.030, 8.535, 2.00, 3.45, 4.56};

    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < 11; j++) {
            if (esta_en(i, j, expectativa_vida, tasa_mortalidad_infantil)) {
                int n = esta_pos(i, j, expectativa_vida, tasa_mortalidad_infantil);
                cout << *(pais + n) << "  ";
            } else {
                cout << "-" << "  ";
            }
        }
        cout << endl;
    }
}

vector<int> hallar_divisores(int n) {
    vector<int> temp;
    for (int i=1; i <= n; i++) {
        if (n % i == 0) {
            temp.push_back(i);
        }
    }
    return temp;
}

void e3() {
    int n;
    cout << "Ingrese un numero:";
    cin >> n;
    vector<int> resultado = hallar_divisores(n);
    cout << "Los divisores son: ";
    for (auto iter: resultado) {
        cout << iter << " ";
    }
}

void e4() {
    int n;
    cout << "Ingrese la cantidad:";
    cin >> n;
    vector<int> numeros(n);
    cout << "Ingrese los numeros:";
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    // mayor numero de repeticiones IMPAR
    int cont = 0;
    for (int i = 0; i < n; i++) {
        int c_interno = 0;
        for (int j = 0; j < n; j++) {
            if (numeros[i] == numeros[j]) {
                c_interno++;
            }
        }
        if (c_interno % 2 == 1) {
            if (c_interno > cont) {
                cont = c_interno;
            }
        }
    }
    // menor numero con la mayor cantidad de repeticiones IMPAR
    int menor_num = INT_MAX;
    for (int i = 0; i < n; i++) {
        int c_interno = 0;
        for (int j = 0; j < n; j++) {
            if (numeros[i] == numeros[j]) {
                c_interno++;
            }
        }
        if (c_interno == cont) {
            if (numeros[i] < menor_num) {
                menor_num = numeros[i];
            }
        }
    }
    if (cont != 0) {
        cout << "El resultado es " << menor_num;
    } else {
        cout << "El resultado es 0";
    }
}

void imprimir(char **mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void e5() {
    int m, n;
    cout << "(filas, columnas)";
    cin >> n >> m;

    char **matriz = new char*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new char[m];
        for (int j = 0; j < m; j++) {
            int azar = rand()%2;
            matriz[i][j] = (azar == 1) ? 'B' : 'W';
        }
    }
    imprimir(matriz, n, m);
    cout << endl;

    char **matriz2 = new char*[n];
    for (int i = 0; i < n; i++) {
        matriz2[i] = new char[m];
        for (int j = 0; j < m; j++) {
            matriz2[i][j] = (matriz[i][j] == 'W') ? 'B' : 'W';
        }
    }
    imprimir(matriz2, n, m);

}

void e6() {
    int n;
    cout << "Cantidad de participantes:";
    cin >> n;

    int **matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matriz[i][j] = -1;
        }
    }

    // 0 -> pierde
    // 1 -> gana
    // -1 -> cuando posicion [i][i] es igual
    // 2 -> empate
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int n = rand()%3;
            matriz[i][j] = n;
            switch (n) {
                case 0:
                    matriz[j][i] = 1;
                    break;
                case 1:
                    matriz[j][i] = 0;
                    break;
                case 2:
                    matriz[j][i] = 2;
                    break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            switch (matriz[i][j]) {
                case 0:
                case 1:
                    cout << matriz[i][j] << "    ";
                    break;
                case 2:
                    cout << "1/2" << " ";
                    break;
                case -1:
                    cout << "     ";
                    break;
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        double puntaje = 0;
        for (int j = 0; j < n; j++) {
            switch (matriz[i][j]) {
                case 0:
                case 1:
                    puntaje += matriz[i][j];
                    break;
                case 2:
                    puntaje += 0.5;
                    break;
                case -1:
                    break;
            }
        }
        cout << "Participante " << i + 1 << ": " << puntaje << " punto" << endl;
    }
}

int main() {
    srand(time(nullptr));

    e1();
    e2();
    e3();
    e4();
    e5();
    e6();
    return 0;
}
