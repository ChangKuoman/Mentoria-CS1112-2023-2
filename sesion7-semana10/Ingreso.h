//
// Created by Samanta on 18/10/2023.
//

#ifndef SESION7_SEMANA10_INGRESO_H
#define SESION7_SEMANA10_INGRESO_H


class Ingreso {
private:
    int mes;
    double monto;
public:
    Ingreso(int mes, double monto);

    int getMes() const;

    void setMes(int mes);

    void setMonto(double monto);

    double getMonto() const;

    virtual ~Ingreso();
};


#endif //SESION7_SEMANA10_INGRESO_H
