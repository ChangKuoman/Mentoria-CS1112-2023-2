//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_EMPLEADO_H
#define SESION8_SEMANA11_EMPLEADO_H

#include "Persona.h"

class Empleado: public Persona {
private:
    double sueldo;
    string fecha;
public:
    Empleado(string n, string d, string dom, double s, string f): Persona(n, d, dom), sueldo(s), fecha(f) {}
    void mostrar() override {
        Persona::mostrar();
        cout << "--- EMPLEADO ---" << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Fecha: " << fecha << endl;
    }
};


#endif //SESION8_SEMANA11_EMPLEADO_H
