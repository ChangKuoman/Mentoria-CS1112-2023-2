//
// Created by Samanta on 18/10/2023.
//

#ifndef SESION7_SEMANA10_AUTOR_H
#define SESION7_SEMANA10_AUTOR_H

#include <iostream>
using namespace std;

class Autor {
private:
    string nombre;
    string apellido;
public:
    Autor(const string &nombre, const string &apellido);

    virtual ~Autor();

    const string &getNombre() const;

    const string &getApellido() const;

    void setNombre(const string &nombre);

    void setApellido(const string &apellido);

    void imprimirAutor() {
        cout << "--- AUTOR ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
    }
};


#endif //SESION7_SEMANA10_AUTOR_H
