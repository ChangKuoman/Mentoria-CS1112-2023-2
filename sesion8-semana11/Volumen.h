//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_VOLUMEN_H
#define SESION8_SEMANA11_VOLUMEN_H

#include <iostream>
using namespace std;

class Volumen {
protected:
    string name;
    int number;
public:
    Volumen(string n, int nu): name(n), number(nu) {}
    void show() {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

#endif //SESION8_SEMANA11_VOLUMEN_H
