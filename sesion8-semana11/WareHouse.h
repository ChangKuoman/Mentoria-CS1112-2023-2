//
// Created by Samanta on 25/10/2023.
//

#ifndef SESION8_SEMANA11_WAREHOUSE_H
#define SESION8_SEMANA11_WAREHOUSE_H

#include "Slot.h"
#include <iostream>
#include <vector>
using namespace std;

class WareHouse {
private:
    string address;
    vector<Slot*> slots;
public:
    WareHouse(string a, int r, int c): address(a) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                slots.push_back(new Slot(i, j));
            }
        }
    }
    ~WareHouse() {
        for (auto iter: slots) {
            delete iter;
        }
        cout << "WareHouse destroyed" << endl;
    }

    bool isSlotAvailable(int row, int column) {
        for (auto iter: slots) {
            if (iter->getColumn() == column && iter->getRow() == row) {
                if (iter->getProductQuatity() == 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        return false;
    }
    void addProductQuantity(int row, int column, int quantity) {
        for (auto iter: slots) {
            if (iter->getColumn() == column && iter->getRow() == row) {
                for (int i = 0; i < quantity; i++) {
                    iter->addProductQuantity();
                }
            }
        }
    }
};

#endif //SESION8_SEMANA11_WAREHOUSE_H
