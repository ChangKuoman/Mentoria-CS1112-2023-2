//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_PERSONA_H
#define SESION8_SEMANA11_PERSONA_H

#include <iostream>

using namespace std;

class Persona {
protected:
    string nombre;
    string dni;
    string domicilio;
public:
    Persona(string n, string d, string dom): nombre(n), dni(d), domicilio(dom) {}
    virtual void mostrar() {
        cout << "--- PERSONA ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "DNI: " << dni << endl;
        cout << "Domicilio: " << domicilio << endl;
    }
    string getNombre() {
        return nombre;
    }
    string getDNI() {
        return dni;
    }
    string getDomicilio() {
        return domicilio;
    }
};

#endif //SESION8_SEMANA11_PERSONA_H
