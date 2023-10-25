//
// Created by Samanta on 25/10/2023.
//

#include "Motor.h"

const string &Motor::getModelo() const {
    return modelo;
}

bool Motor::isEncendido() const {
    return encendido;
}

Motor::Motor(const string &modelo) : modelo(modelo) {
    encendido = false;
}

Motor::~Motor() {

}
void Motor::encender() {
    encendido = true;
}

void Motor::apagar() {
    encendido = false;
}