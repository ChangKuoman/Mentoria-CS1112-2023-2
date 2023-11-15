#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void ejericio1() {
    fstream archivo("notas.txt", ios::out);

    string valor;
    cout << "Ingrese cinco palabras:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> valor;
        archivo << valor;
        archivo << '\n';
    }
    archivo.close();

    fstream archivo2("notas.txt", ios::in);

    while (archivo2 >> valor) {
        cout << valor << endl;
    }
    archivo2.close();
}

class Calificacion {
protected:
    char tipo;
    int codigo;
    string nombre;
    int pc1;
    int pc2;
public:
    Calificacion(char t, int c, string n, int pc1, int pc2):
        tipo(t), codigo(c), nombre(n), pc1(pc1), pc2(pc2) {}
    virtual const float calcularNotaFinal()=0;
    virtual void imprimir() {
        cout << "Codigo:" << codigo << endl;
        cout << "Nombre:" << nombre << endl;
        cout << "PC1:" << pc1 << endl;
        cout << "PC2:" << pc2 << endl;
    }
    char getTipo() {
        return tipo;
    }
    string getNombre() {
        return nombre;
    }
    int getCodigo() {
        return codigo;
    }
};

class CalificacionEjecutivo: public Calificacion {
private:
    int pc3;
public:
    CalificacionEjecutivo(char t, int c, string n, int pc1, int pc2, int pc3):
            Calificacion(t, c, n, pc1, pc2), pc3(pc3) {}
    float const calcularNotaFinal() override {
        return 0.3 * pc1 + 0.3 * pc2 + 0.4 * pc3;
    }
    void imprimir() {
        cout << "--- EJECUTIVO ---" << endl;
        Calificacion::imprimir();
        cout << "PC3:" << pc3 << endl;
    }
};

class CalificacionProgramador: public Calificacion {
private:
    int tf;
public:
    CalificacionProgramador(char t, int c, string n, int pc1, int pc2, int tf):
            Calificacion(t, c, n, pc1, pc2), tf(tf) {}
    float const calcularNotaFinal() override {
        return 0.25 * pc1 + 0.25 * pc2 + 0.5 * tf;
    }
    void imprimir() {
        cout << "--- PROGRAMADOR ---" << endl;
        Calificacion::imprimir();
        cout << "TF:" << tf << endl;
    }
};




class Academia {
private:
    vector<Calificacion*> calificaciones;
public:
    Academia(string nombreArchivo) {
        fstream archivo(nombreArchivo, ios::in);
        string temporal, temporal2;
        while (getline(archivo, temporal)) {
            vector <string> strings;
            int startIndex = 0, endIndex = 0;
            for (int i = 0; i <= temporal.size(); i++) {
                if (temporal[i] == ',' || i == temporal.size()) {
                    endIndex = i;
                    string temp;
                    temp.append(temporal, startIndex, endIndex - startIndex);
                    strings.push_back(temp);
                    startIndex = endIndex + 1;
                }
            }

            if (strings[0] == "E") {
                calificaciones.push_back(new CalificacionEjecutivo(
                        'E', stoi(strings[1]), strings[2], stoi(strings[3]), stoi(strings[4]), stoi(strings[5])
                        ));
            }
            else if (strings[0] == "P"){
                calificaciones.push_back(new CalificacionProgramador(
                        'P', stoi(strings[1]), strings[2], stoi(strings[3]), stoi(strings[4]), stoi(strings[5])
                        ));
            }

        }
        archivo.close();
    }
    void ordenar() {
        sort(calificaciones.begin(), calificaciones.end(), [](Calificacion* lhs, Calificacion* rhs) {
            return lhs->calcularNotaFinal() > rhs->calcularNotaFinal();
        });
    }
    void listarCalificacion(char tipo, string nombreArchivo) {
        fstream archivo(nombreArchivo, ios::out);
        archivo << "Tipo,Codigo,Nombre,NotaFinal\n";
        for (auto iter: calificaciones) {
            if (iter->getTipo() == tipo) {
                archivo << iter->getTipo();
                archivo << ",";
                archivo << to_string(iter->getCodigo());
                archivo << ",";
                archivo << iter->getNombre();
                archivo << ",";
                archivo << to_string(iter->calcularNotaFinal());
                archivo << "\n";
            }
        }

        /*
        for (auto iter: calificaciones) {
            iter->imprimir();
        }
         */
    }
    ~Academia() {
        for (auto iter: calificaciones) {
            delete iter;
        }
    }
};

void ejercicio2() {
    Academia a("calificaciones.csv");
    a.ordenar();
    a.listarCalificacion('P', "programadores.csv");
    a.listarCalificacion('E', "ejecutivos.csv");
}

void ejercicio3() {
    //fstream archivo("D:\\2 UTEC\\6 CICLO\\Mentoria-CS1112-2023-2\\sesion10-semana14\\notas.txt", ios::out);
    // fstream archivo("../notas2.txt", ios::out);
    fstream archivo("../archivos/notas.txt", ios::out);
    archivo << "HOLA\n";
    archivo.close();
}

int main() {

    // crear un archivo con numeros del 1 a 100
    fstream archivo1("../numeros.dat", ios::out);
    for (int i = 1; i < 101; i++) {
        archivo1 << i << endl;
    }
    archivo1.close();

    // leer ese archivo y crear dos archivos, 1 con multiplos de 5 y el otro con multiplos de 7
    fstream archivoLectura("../numeros.dat", ios::in);
    fstream archivo2("../mult5.dat", ios::app);
    fstream archivo3("../mult7.dat", ios::app);

    int lectura;
    while (archivoLectura >> lectura) {
        if (lectura % 5 == 0) {
            archivo2 << lectura << endl;
        }
        if (lectura % 7 == 0) {
            archivo3 << lectura << endl;
        }
    }

    archivo2.close();
    archivo3.close();
    archivoLectura.close();

    fstream archivoX("../numeros.dat", ios::in);
    string value;
    archivoX >> value;
    if (value != "") {
        archivoX.close();
    }
    else {
        cout << "HOLA" ;
    }

    return 0;
}
