#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<string> Split(string cadena, char separator = ',') {
    vector<string> strings;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= cadena.size(); i++) {
        if (cadena[i] == separator || i == cadena.size()) {
            endIndex = i;
            string temp;
            temp.append(cadena, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
}

class Postulante {
protected:
    char facultad;
    string dni;
    string nombreCompleto;
    int lectura;
    int redaccion;
    int matematica;
public:
    Postulante(char f, string d, string n, int l, int r, int m):
        facultad(f), dni(d), nombreCompleto(n), lectura(l), redaccion(r), matematica(m) {}
    virtual float calificacion()=0;
    char getFacultad() {
        return facultad;
    }
    string getDNI() {
        return dni;
    }
    string getNombre() {
        return nombreCompleto;
    }
};

class PostulanteCiencias: public Postulante{
public:
    PostulanteCiencias(char f, string d, string n, int l, int r, int m):
            Postulante(f, d, n, l, r, m) {}
    float calificacion() override {
        return 10 * (lectura + redaccion) + 7.5 * (matematica);
    }
};

class PostulanteLetras: public Postulante{
public:
    PostulanteLetras(char f, string d, string n, int l, int r, int m):
            Postulante(f, d, n, l, r, m) {}
    float calificacion() override {
        return 7.5 * (lectura + redaccion) + 10 * (matematica);
    }
};

class Examen{
private:
    vector<Postulante*> postulantes;
public:
    Examen(string nombreArchivoPostulantes) {
        fstream archivo("../postulantes.csv", ios::in);

        string temporal;
        while(getline(archivo, temporal)) {
            vector<string> datos = Split(temporal, ',');
            if (datos[0] == "L") {
                postulantes.push_back(
                    new PostulanteLetras('L', datos[1], datos[2], stoi(datos[3]), stoi(datos[4]), stoi(datos[5]))
                );
            }
            else { // datos[0] == "C"
                postulantes.push_back(
                        new PostulanteCiencias('C', datos[1], datos[2], stoi(datos[3]), stoi(datos[4]), stoi(datos[5]))
                );
            }
        }

        archivo.close();
    }
    void ordenar() {
        sort(postulantes.begin(), postulantes.end(), [](Postulante* lhs, Postulante* rhs) {
            if (lhs->calificacion() == rhs->calificacion()) {
                return lhs->getNombre() < rhs->getNombre();
            }
            return lhs->calificacion() > rhs->calificacion();
        });
    }
    void listarIngresatesCiencia(string nombreArchivo) {
        fstream archivo(nombreArchivo, ios::out);

        for (auto iter: postulantes) {
            if (iter->getFacultad() == 'C') {
                string temporal = "C,";
                temporal += iter->getDNI() + ",";
                temporal += iter->getNombre() + ",";
                temporal += to_string(iter->calificacion()) + "\n";
                archivo << temporal;
            }
        }

        archivo.close();
    }
    void listarIngresanteLetras(string nombreArchivo) {
        fstream archivo(nombreArchivo, ios::out);

        for (auto iter: postulantes) {
            if (iter->getFacultad() == 'L') {
                string temporal = "L,";
                temporal += iter->getDNI() + ",";
                temporal += iter->getNombre() + ",";
                temporal += to_string(iter->calificacion()) + "\n";
                archivo << temporal;
            }
        }

        archivo.close();
    }
    ~Examen() {
        for (auto iter: postulantes) {
            delete iter;
        }
    }
};

void pc() {
    Examen* examen = new Examen("postulantes.csv");
    examen->ordenar();
    examen->listarIngresanteLetras("../letras.csv");
    examen->listarIngresatesCiencia("../ciencias.csv");

    delete examen;
}

class Persona{
protected:
    string nombre;
    string apellido;
    int edad;
    string dni;
public:
    Persona() {}
    Persona(string n, string a, string d, int e):
        nombre(n), apellido(a), edad(e), dni(d) {}
    virtual void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Edad: " << edad << endl;
        cout << "DNI: " << dni << endl;
    }
    virtual int getTipo()=0;
    virtual string write()=0;
};

class Alumno: public Persona {
private:
    int ciclo;
public:
    Alumno() {}
    Alumno(string n, string a, string d, int e):
        Persona(n, a, d, e) {
        ciclo = rand()%10+1;
    }
    Alumno(string n, string a, string d, int e, int c):
            Persona(n, a, d, e), ciclo(c) {
    }
    void mostrar() override {
        cout << "--- ALUMNO ---" << endl;
        Persona::mostrar();
        cout << "Ciclo: " << ciclo << endl;
    }
    int getCiclo() {
        return ciclo;
    }
    int getTipo() override{
        return 1;
    }
    string write() override {
        return nombre + "," + apellido + "," + dni + "," + to_string(edad) + "," + to_string(ciclo) + '\n';
    }

};

class Profesor: public Persona {
private:
    int sueldo;
public:
    Profesor() {}
    Profesor(string n, string a, string d, int e):
            Persona(n, a, d, e) {
        sueldo = rand()%5000+5000;
    }
    Profesor(string n, string a, string d, int e, int s):
            Persona(n, a, d, e), sueldo(s) {}
    void mostrar() override {
        cout << "--- PROFESOR ---" << endl;
        Persona::mostrar();
        cout << "Sueldo: " << sueldo << endl;
    }
    int getSueldo() {
        return sueldo;
    }
    int getTipo() override{
        return 0;
    }
    string write() override {
        return nombre + "," + apellido + "," + dni + "," + to_string(edad) + "," + to_string(sueldo) + '\n';
    }
};

int main() {
    srand(time(nullptr));
    vector<Persona*> personas;
    vector<string> nombres = {
            "Ana", "Luisa", "Mariana", "Kylie", "Miguel",
            "Juan", "Karla", "Lucia", "Pepe", "Timoteo"
    };
    vector<string> apellidos = {
            "Mendes", "Perez", "Chavez", "Contreras", "Lapa",
            "Vera", "Quispe", "Aguirre", "Saavedra", "Lozano"
    };
    for (int i = 0; i < 20; i++) {
        int tipo = rand()%2;
        if (tipo == 0) {
            // alumno
            personas.push_back(
                new Alumno(nombres[rand()%10], apellidos[rand()%10], to_string(rand()%100), rand()%20 + 20)
            );
        }
        else {
            // tipo = 1 -> profesor
            personas.push_back(
                new Profesor(nombres[rand()%10], apellidos[rand()%10], to_string(rand()%100), rand()%50 + 30)
            );
        }
    }
    for (auto iter: personas) {
        iter->mostrar();
    }

    fstream archivo_alumnos("../alumnos.txt", ios::out);
    fstream archivo_profesores("../profesores.txt", ios::out);
    for (auto &iter: personas) {
        if (iter->getTipo() == 0) {
            archivo_profesores <<  iter->write();
        }
        else {
            archivo_alumnos <<  iter->write();
            // alumno
        }
    }
    archivo_profesores.close();
    archivo_alumnos.close();

    // librera memoria
    for (auto iter: personas) {
        delete iter;
    }

    // leer archivos
    vector<Profesor*> profesores;
    vector<Alumno*> alumnos;

    fstream archivo_r_alumnos("../alumnos.txt", ios::in);
    fstream archivo_r_profesores("../profesores.txt", ios::in);

    string temporal;
    while(getline(archivo_r_alumnos, temporal)) {
        vector<string> datos = Split(temporal, ',');
        alumnos.push_back(
            new Alumno(datos[0], datos[1], datos[2], stoi(datos[3]), stoi(datos[4]))
        );
    }
    while(getline(archivo_r_profesores, temporal)) {
        vector<string> datos = Split(temporal, ',');
        profesores.push_back(
                new Profesor(datos[0], datos[1], datos[2], stoi(datos[3]), stoi(datos[4]))
        );
    }
    archivo_r_alumnos.close();
    archivo_r_profesores.close();

    // profesores
    int sueldo_min = INT_MAX;
    int sueldo_max = 0;
    Profesor* smin = nullptr;
    Profesor* smax = nullptr;
    for (auto iter: profesores) {
        if (iter->getSueldo() < sueldo_min) {
            sueldo_min = iter->getSueldo();
            smin = iter;
        }
        if (iter->getSueldo() > sueldo_max) {
            sueldo_max = iter->getSueldo();
            smax = iter;
        }
    }
    cout << "El profesor con sueldo maximo es:" << endl;
    smax->mostrar();

    cout << "El profesor con sueldo minimo es:" << endl;
    smin->mostrar();

    // CANT alumnos x ciclo

    vector<int> ciclos = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (auto iter:alumnos) {
        ciclos[iter->getCiclo()-1]++;
    }
    cout << "Alumnos por ciclo:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << "Ciclo " << i+1 << ": " << ciclos[i] << endl;
    }

    cout << "------------------------------" << endl;
    for (auto iter: alumnos) {
        iter->mostrar();
    }

    for (auto iter: profesores) {
        iter->mostrar();
    }
    // liberar memoria
    for (auto iter: profesores){
        delete iter;
    }
    for (auto iter: alumnos){
        delete iter;
    }
    return 0;
}
