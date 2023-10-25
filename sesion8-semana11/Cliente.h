//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_CLIENTE_H
#define SESION8_SEMANA11_CLIENTE_H

#include "Persona.h"

class Cliente: public Persona {
private:
    string telefono;
public:
    Cliente(string n, string d, string dom, string t): Persona(n, d, dom), telefono(t) {}
    Cliente(Empleado* empleado, string t) :
            Persona(empleado->getNombre(), empleado->getDomicilio(), empleado->getDNI()),
            telefono(t) {}

    void mostrar() override {
        Persona::mostrar();
        cout << "--- CLIENTE ---" << endl;
        cout << "Telefono: " << telefono << endl;
    }
};

#endif //SESION8_SEMANA11_CLIENTE_H
