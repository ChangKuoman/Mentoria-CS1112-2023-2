//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_NEWSPAPER_H
#define SESION8_SEMANA11_NEWSPAPER_H

#include "Volumen.h"

class NewsPaper: public Volumen {
private:
    string issn;
public:
    NewsPaper(string n, int nu, string issn): Volumen(n, nu), issn(issn) {}
    void show() {
        cout << "--- NEWSPAPER ---" << endl;
        Volumen::show();
        cout << "ISSN: " << issn << endl;
    }
};

#endif //SESION8_SEMANA11_NEWSPAPER_H
