//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_SLOT_H
#define SESION8_SEMANA11_SLOT_H

class Slot {
private:
    int row;
    int column;
    int productQuantity;
public:
    Slot(int r, int c): row(r), column(c), productQuantity(0) {}
    ~Slot() {
        cout << "Slot destoyed" << endl;
    }
    int getProductQuatity() {
        return productQuantity;
    }
    void addProductQuantity() {
        productQuantity++;
    }
    int getRow() {
        return row;
    }
    int getColumn() {
        return column;
    }
};

#endif //SESION8_SEMANA11_SLOT_H
