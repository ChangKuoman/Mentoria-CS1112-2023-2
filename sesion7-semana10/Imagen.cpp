//
// Created by Samanta on 18/10/2023.
//

#include "Imagen.h"

Imagen::Imagen() {
    this->width = 5;
    this->height = 5;
    this->matriz = new int*[height];
    for (int i = 0; i < height; i++) {
        this->matriz[i] = new int[width];
        for (int j = 0; j < height; j++) {
            this->matriz[i][j] = 1;
        }
    }
}

Imagen::Imagen(int width, int height, int valor) : width(width), height(height) {
    this->matriz = new int*[height];
    for (int i = 0; i < height; i++) {
        this->matriz[i] = new int[width];
        for (int j = 0; j < height; j++) {
            this->matriz[i][j] = valor;
        }
    }
}

int Imagen::getWidth() const {
    return width;
}

int Imagen::getHeight() const {
    return height;
}

int **Imagen::getMatriz() const {
    return matriz;
}

void Imagen::setWidth(int width) {
    Imagen::width = width;
}

void Imagen::setHeight(int height) {
    Imagen::height = height;
}

void Imagen::setMatriz(int **matriz) {
    Imagen::matriz = matriz;
}

Imagen::~Imagen() {
    for (int i = 0; i < height; i++) {
        delete []this->matriz[i];
    }
    delete []this->matriz;
    this->matriz = nullptr;
}

void Imagen::giroAntihorario() {
    int **temporal = new int*[this->width];

    for (int i = 0; i < this->width; i++) {
        temporal[i] = new int[this->height];
        for (int j = 0; j < this->height; j++) {
            temporal[i][j] = this->matriz[j][width - i - 1];
        }
    }
    this->matriz = temporal;
    int t_width = this->width;
    int t_height = this->height;
    this->height = t_width;
    this->width = t_height;
}

void Imagen::imprimirMatriz() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            cout << this->matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}