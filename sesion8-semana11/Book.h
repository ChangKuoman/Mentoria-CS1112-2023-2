//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_BOOK_H
#define SESION8_SEMANA11_BOOK_H

#include "Volumen.h"

class Book: public Volumen {
private:
    string isbn;
public:
    Book(string n, int nu, string isbn): Volumen(n, nu), isbn(isbn) {}
    void show() {
        cout << "--- BOOK ---" << endl;
        Volumen::show();
        cout << "ISBN: " << isbn << endl;
    }
};

#endif //SESION8_SEMANA11_BOOK_H
