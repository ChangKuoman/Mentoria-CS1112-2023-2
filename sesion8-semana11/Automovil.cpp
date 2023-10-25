//
// Created by Samanta on 25/10/2023.
//

#include "Automovil.h"

const string &Automovil::getMarca() const {
    return marca;
}

const string &Automovil::getModelo() const {
    return modelo;
}

int Automovil::getAnho() const {
    return anho;
}

Motor *Automovil::getMotor() const {
    return motor;
}

Tanque *Automovil::getTanque() const {
    return tanque;
}

Automovil::~Automovil() {

}

Automovil::Automovil(const string &marca, const string &modelo, int anho, Motor *motor, Tanque *tanque) : marca(marca),
                                                                                                          modelo(modelo),
                                                                                                          anho(anho),
                                                                                                          motor(motor),
                                                                                                          tanque(tanque) {
    encendido = false;
}

void Automovil::arrancarAutomovil() {
    if (motor->isEncendido() == true) {
        encendido = true;
    }
}

void Automovil::apagarAutomovil() {
    if (motor->isEncendido() == true) {
        encendido = false;
    }
}

void Automovil::avanzarAutomovil(int distancia) {
    if (encendido == true) {
        cout << "Se avanzo " << distancia << " distancia." << endl;
    }
}
