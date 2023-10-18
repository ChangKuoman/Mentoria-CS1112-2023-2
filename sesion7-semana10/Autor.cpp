//
// Created by Samanta on 18/10/2023.
//

#include "Autor.h"

Autor::Autor(const string &nombre, const string &apellido) : nombre(nombre), apellido(apellido) {}

Autor::~Autor() {

}

const string &Autor::getNombre() const {
    return nombre;
}

const string &Autor::getApellido() const {
    return apellido;
}

void Autor::setNombre(const string &nombre) {
    Autor::nombre = nombre;
}

void Autor::setApellido(const string &apellido) {
    Autor::apellido = apellido;
}
