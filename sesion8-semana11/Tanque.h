//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_TANQUE_H
#define SESION8_SEMANA11_TANQUE_H


class Tanque {
private:
    int capacidad;
    int cantidadCombustible;
public:
    int getCapacidad() const;

    int getCantidadCombustible() const;

    Tanque(int capacidad, int cantidadCombustible);

    virtual ~Tanque();

};


#endif //SESION8_SEMANA11_TANQUE_H
