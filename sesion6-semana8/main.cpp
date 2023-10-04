#include <iostream>
#include <vector>
using namespace std;

int ** sumar_circundantes ( int ** origen , int lado ) ;

void ej1() {
    int n;
    cout << "n:";
    cin >> n;

    int **matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    int **matriz_resultado = sumar_circundantes(matriz, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz_resultado[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete []matriz[i];
        delete []matriz_resultado[i];
    }
    delete []matriz;
    delete []matriz_resultado;
}

vector < string > obtener_palabras ( const string & origen ) ;

void ej2() {
    string origen;
    getline(cin, origen);
//    cin >> origen;
    vector<string> res = obtener_palabras(origen);
    cout << res.size() << endl;
    for (auto elem: res) {
        cout << elem << endl;
    }
}

class producto_t {
private:
    string name;
    double price;
    char currency;
    double exchange;
public:
    producto_t(string nombre, char tmoneda, double tcambio, double precio) {
        name = nombre;
        price = precio;
        currency = tmoneda;
        exchange = tcambio;
    }

    string get_name() {
        return name;
    }

    char get_currency() {
        return currency;
    }

    double get_price(char curr) {
        if (currency == curr) {
            return price;
        }
        else {
            if (curr == 'D') {
                return price / exchange;
            }
            else if (curr == 'S') {
                return price * exchange;
            }
        }
    }
};

void ej3() {
    int n;
    cout << "n:";
    cin >> n;
    vector <producto_t> productos;

    string nombre;
    char tmoneda;
    double precio, tcambio;
    for (int i = 0; i < n; i++) {
        cout << "Nombre:";
//        cin >> nombre;
        cin.ignore();
        getline(cin, nombre);
        cout << "Tipo moneda (S, D):";
        cin >> tmoneda;
        cout << "Tipo cambio:";
        cin >> tcambio;
        cout << "Precio:";
        cin >> precio;
        producto_t prod_temp(nombre, tmoneda, tcambio, precio);
        productos.push_back(prod_temp);
    }
    char final;
    cout << "S/D:";
    cin >> final;
    double suma = 0;
    for (int i = 0; i < n; i++) {
        cout << productos[i].get_name() << " - " << productos[i].get_price(final) << endl;
        suma += productos[i].get_price(final);
    }
    cout << "Total = " << suma << endl;
}

struct profesor {

};

class alumno {
private:
    string codigo;
    string nombre;
    int edad;
public:
    alumno() {}
    alumno(string n) {
        nombre = n;
    }
    alumno(int numero): edad(numero), nombre("Sin Nombre") {}

    void set_codigo(string c) {
        codigo = c;
    }
    string get_codigo() {
        return codigo;
    }
    int get_edad() {
        return edad;
    }

    alumno hallar_mayor(alumno a) {
        if (a.get_edad() > this->get_edad()) {
            return a;
        }
        else {
            return *this;
        }
    }

    ~alumno() {}
};

int main() {
//    ej1();
//    ej2();
//    ej3();
    alumno a1("Jaime");
    alumno a2(16);

    return 0;
}

vector < string > obtener_palabras ( const string & origen ) {
    string o_temp = origen;
    o_temp += " ";
    vector<string> temp;
    string palabra;
    for (auto letra: o_temp) {
        if (letra == ' ' or letra == '.' or letra == ',') {
            temp.push_back(palabra);
            palabra = "";
        }
        else {
            palabra += letra;
        }
    }
//    temp.push_back(palabra);

    return temp;
}

int ** sumar_circundantes ( int ** origen , int lado) {
    int **temporal = new int*[lado];
    for (int i = 0; i < lado; i++) {
        temporal[i] = new int[lado];
        for (int j = 0; j < lado; j++) {
            int suma = 0;
            // esquinas
            if (i == 0 and j == 0) {
                suma += origen[0][1] + origen[1][1] + origen[1][0];
            }
            else if (i == 0 and j == lado - 1) {
                suma += origen[0][lado-2] + origen[1][lado-2] + origen[1][lado-1];
            }
            else if (i == lado - 1 and j == 0) {
                suma += origen[lado - 2][0] + origen[lado - 2][1] + origen[lado-1][1];
            }
            else if (i == lado - 1 and j == lado - 1) {
                suma += origen[lado-2][lado-2] + origen[lado-1][lado-2] + origen[lado-2][lado-1];
            }
            else if (i == 0) {
                suma += origen[i][j-1] + origen[i][j+1] + origen[i+1][j-1] + origen[i+1][j] + origen[i+1][j+1];
            }
            else if (j == 0) {
                suma += origen[i+1][j] + origen[i-1][j] + origen[i+1][j+1] + origen[i][j+1] + origen[i-1][j+1];
            }
            else if (i == lado - 1) {
                suma += origen[i][j-1] + origen[i][j+1] + origen[i-1][j+1] + origen[i-1][j] + origen[i-1][j-1];
            }
            else if (j == lado - 1) {
                suma += origen[i+1][j] + origen[i-1][j] + origen[i+1][j-1] + origen[i][j-1] + origen[i-1][j-1];
            }
            else {
                suma += origen[i-1][j-1]
                        + origen[i-1][j]
                        + origen[i-1][j+1]

                        + origen[i][j+1]
                        // origen [i][j]
                        + origen[i][j-1]

                        + origen[i+1][j-1]
                        + origen[i+1][j]
                        + origen[i+1][j+1];
            }
            temporal[i][j] = suma;
        }
    }
    return temporal;
}