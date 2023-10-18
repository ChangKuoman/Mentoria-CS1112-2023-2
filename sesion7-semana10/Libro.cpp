//
// Created by Samanta on 18/10/2023.
//

#include "Libro.h"

Libro::Libro(const string &titulo, const string &genero, Autor *autor) : titulo(titulo), genero(genero), autor(autor) {}

Libro::~Libro() {

}

const string &Libro::getTitulo() const {
    return titulo;
}

const string &Libro::getGenero() const {
    return genero;
}

Autor *Libro::getAutor() const {
    return autor;
}

void Libro::setTitulo(const string &titulo) {
    Libro::titulo = titulo;
}

void Libro::setGenero(const string &genero) {
    Libro::genero = genero;
}

void Libro::setAutor(Autor *autor) {
    Libro::autor = autor;
}
