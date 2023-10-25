//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_HOTEL_H
#define SESION8_SEMANA11_HOTEL_H

#include "Habitacion.h"
#include <vector>
#include <iostream>

using namespace std;

class Hotel {
private:
    string nombre;
    vector<Habitacion*> habitaciones;
public:
    Hotel(string n): nombre(n) {}
    ~Hotel() {
        for (auto iter: habitaciones) {
            delete iter;
        }
    }
    void insertarHabitacion(Habitacion* h) {
        habitaciones.push_back(h);
    }
    int calcularDisponibles(int tipo) {
        int suma = 0;
        for (auto iter: habitaciones) {
            if (iter->getTipoHab() == tipo && iter->getDisponible()) {
                suma++;
            }
        }
        return suma;
    }
};


#endif //SESION8_SEMANA11_HOTEL_H
