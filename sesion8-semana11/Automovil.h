//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_AUTOMOVIL_H
#define SESION8_SEMANA11_AUTOMOVIL_H

#include <iostream>
#include "Tanque.h"
#include "Motor.h"
using namespace std;

class Automovil {
private:
    string marca;
    string modelo;
    int anho;
    Motor* motor;
    Tanque* tanque;
    bool encendido;
public:
    const string &getMarca() const;

    Automovil(const string &marca, const string &modelo, int anho, Motor *motor, Tanque *tanque);

    const string &getModelo() const;

    int getAnho() const;

    virtual ~Automovil();

    Motor *getMotor() const;

    Tanque *getTanque() const;

    void arrancarAutomovil();
    void apagarAutomovil();
    void avanzarAutomovil(int distancia);

};


#endif //SESION8_SEMANA11_AUTOMOVIL_H
