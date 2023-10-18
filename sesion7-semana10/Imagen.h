//
// Created by Samanta on 18/10/2023.
//

#ifndef SESION7_SEMANA10_IMAGEN_H
#define SESION7_SEMANA10_IMAGEN_H

#include <iostream>

using namespace std;

class Imagen {
private:
    int width;
    int height;
    int** matriz;
public:
    Imagen(int width, int height, int valor);
    Imagen();
    void setWidth(int width);
    void setHeight(int height);
    void setMatriz(int **matriz);
    int getWidth() const;
    int getHeight() const;
    int **getMatriz() const;
    virtual ~Imagen();

    void giroAntihorario();
    void imprimirMatriz();
};


#endif //SESION7_SEMANA10_IMAGEN_H
