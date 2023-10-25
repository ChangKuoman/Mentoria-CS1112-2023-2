//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_SUMA_H
#define SESION8_SEMANA11_SUMA_H

#include "OBinaria.h"

class Suma: public OBinaria {
public:
    Suma(int n1, int n2): OBinaria(n1, n2) {}
    int calcular() override {
        return n1 + n2;
    }
};


#endif //SESION8_SEMANA11_SUMA_H
