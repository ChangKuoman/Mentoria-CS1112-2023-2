//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_HABITACION_H
#define SESION8_SEMANA11_HABITACION_H

class Habitacion {
private:
    int nCamas;
    bool disponible;
    int tipoHab;
public:
    Habitacion(int n, int t): nCamas(n), disponible(true), tipoHab(t) {}
    void setDisponible(bool d) {
        disponible = d;
    }
    bool getDisponible() {
        return disponible;
    }
    int getTipoHab() {
        return tipoHab;
    }
};

#endif //SESION8_SEMANA11_HABITACION_H
