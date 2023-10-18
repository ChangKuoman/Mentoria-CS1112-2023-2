//
// Created by Samanta on 18/10/2023.
//

#include "Ingreso.h"

Ingreso::Ingreso(int mes, double monto) : mes(mes), monto(monto) {}

Ingreso::~Ingreso() {

}

int Ingreso::getMes() const {
    return mes;
}

double Ingreso::getMonto() const {
    return monto;
}

void Ingreso::setMes(int mes) {
    Ingreso::mes = mes;
}

void Ingreso::setMonto(double monto) {
    Ingreso::monto = monto;
}
