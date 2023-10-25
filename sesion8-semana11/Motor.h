//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_MOTOR_H
#define SESION8_SEMANA11_MOTOR_H

#include <iostream>

using namespace std;

class Motor {
private:
    string modelo;
    bool encendido;
public:
    explicit Motor(const string &modelo);

    virtual ~Motor();

    const string &getModelo() const;

    bool isEncendido() const;

    void encender();
    void apagar();
};


#endif //SESION8_SEMANA11_MOTOR_H
