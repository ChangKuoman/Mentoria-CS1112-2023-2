//
// Created by Samanta on 25/10/2023.
//

#include "Tanque.h"

int Tanque::getCapacidad() const {
    return capacidad;
}

int Tanque::getCantidadCombustible() const {
    return cantidadCombustible;
}

Tanque::Tanque(int capacidad, int cantidadCombustible) : capacidad(capacidad),
                                                         cantidadCombustible(cantidadCombustible) {}

Tanque::~Tanque() {

}
