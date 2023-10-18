//
// Created by Samanta on 18/10/2023.
//

#ifndef SESION7_SEMANA10_LIBRO_H
#define SESION7_SEMANA10_LIBRO_H

#include "Autor.h"

class Libro {
private:
    string titulo;
    string genero;
    Autor *autor;
public:
    Libro(const string &titulo, const string &genero, Autor *autor);

    virtual ~Libro();

    const string &getTitulo() const;

    const string &getGenero() const;

    Autor *getAutor() const;

    void setTitulo(const string &titulo);

    void setGenero(const string &genero);

    void setAutor(Autor *autor);

    void imprimirLibro() {
        cout << "--- LIBRO ---" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        autor->imprimirAutor();
        cout << endl;
    }
};


#endif //SESION7_SEMANA10_LIBRO_H
