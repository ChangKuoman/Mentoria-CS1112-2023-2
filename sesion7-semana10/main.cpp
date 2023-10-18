#include <iostream>
#include <vector>
#include "Imagen.h"
#include "Libro.h"
#include "Persona.h"
using namespace std;

int** generarMatrizAleatoria(int n) {
    int **temporal = new int*[n];
    for (int i=0; i<n; i++) {
        temporal[i] = new int[n];
        for (int j=0; j<n; j++) {
            temporal[i][j] = rand()% 5 + 3 ;
        }
    }
    return temporal;
}

void limpiarMatriz(int** matriz, int n) {
    for (int i=0; i<n; i++) {
        delete []matriz[i];
    }
    delete []matriz;
    matriz = nullptr;
}

int** imprimirMatriz(int** matriz, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ej1() {

    int n;
    cout << "Orden de la matriz cuadrada:";
    cin >> n;
    int **matriz1 = generarMatrizAleatoria(n);
    int **matriz2 = generarMatrizAleatoria(n);
    int **matriz3 = generarMatrizAleatoria(n);
    int **matriz4 = generarMatrizAleatoria(n);

    // MODIFICAR LA MATRIZ 3
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // SI SON BORDES: MULTIPLICAMOS
            if (i == 0 or i == n - 1 or j == 0 or j == n - 1) {
                matriz3[i][j] = matriz1[i][j] * matriz2[i][j];
            }
                // SIMO: -1
            else {
                matriz3[i][j] = -1;
            }
        }
    }

    //ROTAR 90 G A LA DERECHA
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // GIRO A LA DERECHA
            matriz4[j][n - i - 1] = matriz3[i][j];
            // GIRO A LA IZQUIERDA
//            matriz4[i][j] = matriz3[j][n - i - 1];
        }
    }

    imprimirMatriz(matriz1, n);
    imprimirMatriz(matriz2, n);
    imprimirMatriz(matriz3, n);
    imprimirMatriz(matriz4, n);

    limpiarMatriz(matriz1, n);
    limpiarMatriz(matriz2, n);
    limpiarMatriz(matriz3, n);
    limpiarMatriz(matriz4, n);
}

void intercambiarValores(vector<int>& v1, vector<int>& v2, int pos) {
    if (v1.size() == v2.size()) {
        for (int i = pos; i < v1.size(); i++) {
            swap(v1[i], v2[i]);
        }
    }
    else if (v1.size() > v2.size()) {
        for (int i = pos; i < v2.size(); i++) {
            swap(v1[i], v2[i]);
        }
        int ini = v2.size();
        int fin = v1.size();
        for (int i = ini; i < fin; i++) {
            v2.push_back(v1[i]);
        }
        for (int i = ini; i < fin; i++) {
            v1.pop_back();
        }
    }
    else if (v2.size() > v1.size()) {
        for (int i = pos; i < v1.size(); i++) {
            swap(v1[i], v2[i]);
        }
        int ini = v1.size();
        int fin = v2.size();
        for (int i = ini; i < fin; i++) {
            v1.push_back(v2[i]);
        }
        for (int i = ini; i < fin; i++) {
            v2.pop_back();
        }
    }
}

void ej2() {
    int n1, n2, aux, pos;
    vector<int> v1, v2;
    cout << "tam1:";
    cin >> n1;
    cout << "vector 1:";
    for (int i = 0; i < n1; i++) {
        cin >> aux;
        v1.push_back(aux);
    }
    cout << "tam2:";
    cin >> n2;
    cout << "vector 2:";
    for (int i = 0; i < n2; i++) {
        cin >> aux;
        v2.push_back(aux);
    }
    cout << "posicion:";
    cin >> pos;
    intercambiarValores(v1, v2, pos);

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
}

void ej3() {
    Imagen img(4, 8, 3);
    img.imprimirMatriz();

    img.giroAntihorario();

    img.imprimirMatriz();
}

void asociacion() {
    int cantLibros;
    cout << "cantidad libros";
    cin >> cantLibros;

    string nombre, apellido;
    cout << "Nombre del autor";
    cin >> nombre;
    cout << "Apellido del autor";
    cin >> apellido;

    Autor autor(nombre, apellido);

    string titulo, genero;
    vector<Libro> libros;
    for (int i = 0; i < cantLibros; i++) {
        cout << "Titulo del libro";
        cin >> titulo;
        cout << "Genero del libro";
        cin >> genero;
        libros.push_back(Libro(titulo, genero, &autor));
    }

    for (auto l: libros) {
        l.imprimirLibro();
    }
}

void agregacion() {
    Persona persona("Juan", "123456789111");
    Ingreso ingreso1(1, 10.5);
    Ingreso ingreso2(2, 50.80);
    Ingreso ingreso3(3, 17);

    persona.insertarIngreso(&ingreso1);
    persona.insertarIngreso(&ingreso2);
    persona.insertarIngreso(&ingreso3);

    cout << persona.calcularImpuesto() << endl;
}

int main() {
    srand(time(nullptr));
//    ej1();
//    ej2();
//    ej3();
//    asociacion();
//    agregacion();

    return 0;
}
