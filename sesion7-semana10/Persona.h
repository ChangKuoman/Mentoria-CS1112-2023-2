//
// Created by Samanta on 18/10/2023.
//

#ifndef SESION7_SEMANA10_PERSONA_H
#define SESION7_SEMANA10_PERSONA_H

#include <iostream>
#include "Ingreso.h"
#include <vector>
using namespace std;

class Persona {
private:
    string nombre;
    string ruc;
    vector<Ingreso*> ingresos;
public:
    Persona(const string &nombre, const string &ruc);
    void insertarIngreso(Ingreso* ingreso) {
        ingresos.push_back(ingreso);
    }
    double calcularImpuesto() {
        double impuesto = 0;
        for (auto iter: ingresos) {
            impuesto += iter->getMonto();
        }
        return impuesto * 0.08;
    }
};


#endif //SESION7_SEMANA10_PERSONA_H
