#include <iostream>
#include <random>
#include <vector>

using namespace std;

int** guardar_espacio(int n) {
    int** matriz;
    matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];

        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand()%5+1;
        }
    }
    return matriz;
}

void imprimir(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void liberar(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        delete []matriz[i];
    }
    delete []matriz;
    matriz = nullptr;
}

void ejercicio1() {
    int n;
    cout << "Orden:";
    cin >> n;

    int **matriz_1 = guardar_espacio(n);
    imprimir(matriz_1, n);
    cout << endl;
    int **matriz_2 = guardar_espacio(n);
    imprimir(matriz_2, n);
    int **matriz_3 = guardar_espacio(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz_1[i][j] == matriz_2[i][j]) {
                matriz_3[i][j] = 1;
            }
            else {
                matriz_3[i][j] = 0;
            }
        }
    }

    cout << endl;
    imprimir(matriz_3, n);

    liberar(matriz_1, n);
    liberar(matriz_2, n);
    liberar(matriz_3, n);
}

void ejercicio2() {
    int n;
    cout << "Orden:";
    cin >> n;

    int **matriz_1 = guardar_espacio(n);
    int **matriz_2 = guardar_espacio(n);
    int **matriz_3 = guardar_espacio(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 or j == 0 or i == n - 1 or j == n - 1) {
                matriz_3[i][j] = matriz_1[i][j] + matriz_2[i][j];
            }
            else {
                matriz_3[i][j] = 0;
            }
        }
    }

    imprimir(matriz_1, n);
    cout << endl;
    imprimir(matriz_2, n);
    cout << endl;
    imprimir(matriz_3, n);


    liberar(matriz_1, n);
    liberar(matriz_2, n);
    liberar(matriz_3, n);
}

void ejercicio3() {
    vector<int> todos;
    vector<int> solo4;
    int n;

    cout << "Numero de elementos:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int elem = rand()%999 + 1;
        todos.push_back(elem);
    }

    for (auto iter: todos) {
        cout << iter << " ";
    }

    for (auto iter: todos) {
        int temporal = iter;
        while (temporal != 0) {
            if (temporal % 10 == 4) {
                solo4.push_back(iter);
                break;
            }
            temporal /= 10;
        }
    }

    cout << endl << "Vector solo con digitos 4:" << endl;

    for (auto iter: solo4) {
        cout << iter << " ";
    }
}

void rota_1_der(vector<char>& cadena) {
    char ultimo_v = cadena[cadena.size() - 1];
    for (int i = cadena.size() - 1; i > 0; i--) {
        cadena[i] = cadena[i - 1];
    }
    cadena[0] = ultimo_v;
}

void rota_1_izq(vector<char>& cadena) {
    char primer_v = cadena[0];
    for (int i = 0; i < cadena.size() - 1; i++) {
        cadena[i] = cadena[i + 1];
    }
    cadena[cadena.size() - 1] = primer_v;
}

void ejercicio4() {
    vector<char> cadena;
    int rot;
    string input;
    cout << "CADENA:";
    cin >> input;
    cout << "NUMERO:";
    cin >> rot;

    for (auto iter: input) {
        cadena.push_back(iter);
    }

    if (rot > 0) {
        for (int i = 0; i < rot; i++) {
            rota_1_der(cadena);
        }
    }
    else if (rot < 0) {
        for (int i = 0; i < abs(rot); i++) {
            rota_1_izq(cadena);
        }
    }

    cout << "RESULTADO:";
    for (auto iter: cadena) {
        cout << iter;
    }
    cout << endl;
}

bool no_se_encuentra(const int* modas, int numero, int total_modas) {
    for (int i = 0; i < total_modas; i++) {
        if (modas[i] == numero) {
            return false;
        }
    }
    return true;
}

void ejercicio5() {
    int n;
    cout << "N:";
    cin >> n;

    int* numeros = new int[n];
    for (int i = 0; i < n; i++) {
        numeros[i] = rand()%10 + 1;
    }

    int cant = 0;

    // hallar el numero de veces que se repite
    for (int i = 0; i < n; i++) {
        int cont_interno = 0;
        for (int j = 0; j < n; j++) {
            if (numeros[i] == numeros[j]) {
                cont_interno++;
            }
        }
        if (cont_interno > cant) {
            cant = cont_interno;
        }
    }

    int total_modas = 0;
    // hallar cuantas modas hay
    for (int i = 0; i < n; i++) {
        int cont_interno = 0;
        for (int j = 0; j < n; j++) {
            if (numeros[i] == numeros[j]) {
                cont_interno++;
            }
        }
        if (cont_interno == cant) {
            total_modas++;
        }
    }
    total_modas = total_modas / cant;

    int *modas = new int[total_modas];
    int k = 0;
    // almacenar cuales son las modas
    for (int i = 0; i < n; i++) {
        int cont_interno = 0;
        for (int j = 0; j < n; j++) {
            if (numeros[i] == numeros[j]) {
                cont_interno++;
            }
        }
        if (cont_interno == cant and no_se_encuentra(modas, numeros[i], total_modas)) {
            modas[k++] = numeros[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    cout << cant << endl;
    cout << total_modas << endl;
    for (int i = 0; i < total_modas; i++) {
        cout << modas[i] << " ";
    }
    cout << endl;

    delete []numeros;
    numeros = nullptr;
    delete []modas;
    modas = nullptr;
}

void ejercicio6() {
    int n;
    int c;
    char op;
    cout << "N:";
    cin >> n;
    cout << "C:";
    cin >> c;
    cout << "OP:";
    cin >> op;

    // crear matriz y llenarla
    int **matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand()%9 + 1;
        }
    }

    imprimir(matriz, n);
    cout << "RESPUESTA:" << endl;

    int respuesta = (op == 'S') ? 0 : 1;
    for (int i = 0; i < n; i++) {
        if (op == 'S') {
            cout << matriz[i][c-1] << (i < n - 1 ? "+" : "");
            respuesta += matriz[i][c - 1];
        }
        else if (op == 'M') {
            cout << matriz[i][c-1] << (i < n - 1 ? "x" : "");
            respuesta *= matriz[i][c - 1];
        }
    }
    cout << "=" << respuesta;
    // eliminar
    for (int i = 0; i < n; i++) {
        delete []matriz[i];
    }
    delete[]matriz;
    matriz = nullptr;
}


void funcion(int inicio, int fin, char opcion, vector<int>& resultado) {
    for (int i = inicio; i <= fin; i++) {
        switch (opcion) {
            case 'p':
                if (i % 2 == 0) {
                    resultado.push_back(i);
                }
                break;
            case 'i':
                if (i % 2 == 1) {
                    resultado.push_back(i);
                }
                break;
            case 'e':
                if (i % 3 == 0) {
                    resultado.push_back(i);
                }
                break;
        }
    }
}

void ejercicio7() {
    int inicio, final;
    char opcion;
    vector<int> resultado;

    cout << "INICIO:";
    cin >> inicio;
    cout << "FINAL:";
    cin >> final;
    cout << "OPCION:";
    cin >> opcion;

    funcion(inicio, final, opcion, resultado);

    cout << "SALIDA: ";
    for (auto iter: resultado) {
        cout << iter << " ";
    }
    cout << endl;
}

void intercambio_vectores(vector<int>& v1, vector<int>& v2, int posicion) {
    if (v1.size() == v2.size()) {
        for (int i = posicion; i < v1.size(); i++) {
            int temporal = v1[i];
            v1[i] = v2[i];
            v2[i] = temporal;
        }
    } else if (v1.size() > v2.size()) {
        for (int i = posicion; i < v2.size(); i++) {
            int temporal = v1[i];
            v1[i] = v2[i];
            v2[i] = temporal;
        }
        int valor_inicial_tam_v2 = v2.size();
        int valor_inicial_tam_v1 = v1.size();
        for (int i = valor_inicial_tam_v2; i < valor_inicial_tam_v1; i++) {
            v2.push_back(v1[i]);
        }
        for (int i = valor_inicial_tam_v2; i < valor_inicial_tam_v1; i++) {
            v1.pop_back();
        }

    } else if (v2.size() > v1.size()) {
        for (int i = posicion; i < v1.size(); i++) {
            int temporal = v1[i];
            v1[i] = v2[i];
            v2[i] = temporal;
        }
        int valor_inicial_tam_v2 = v2.size();
        int valor_inicial_tam_v1 = v1.size();
        for (int i = valor_inicial_tam_v1; i < valor_inicial_tam_v2; i++) {
            v1.push_back(v2[i]);
        }
        for (int i = valor_inicial_tam_v1; i < valor_inicial_tam_v2; i++) {
            v2.pop_back();
        }
    }
}

void ejercicio8() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7, 8, 9};
    intercambio_vectores(v1, v2, 2);

    for (auto iter: v1) cout << iter <<  " ";
    cout << endl;
    for (auto iter: v2) cout << iter <<  " ";
    cout << endl;
}

int main() {
    srand(time(nullptr));

    return 0;
}
