//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_OBINARIA_H
#define SESION8_SEMANA11_OBINARIA_H


class OBinaria {
protected:
    int n1;
    int n2;
public:
    OBinaria(int n1, int n2): n1(n1), n2(n2) {}
    ~OBinaria(){}
    virtual int calcular()=0;
};


#endif //SESION8_SEMANA11_OBINARIA_H
