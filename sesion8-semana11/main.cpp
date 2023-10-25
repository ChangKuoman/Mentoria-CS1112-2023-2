#include <iostream>
#include "Automovil.h"
#include "Suma.h"
#include "Resta.h"
#include "Empleado.h"
#include "Cliente.h"
#include "WareHouse.h"
#include "Hotel.h"
#include "Book.h"
#include "NewsPaper.h"

void composicion() {
    Tanque t(100, 10);
    Motor m("ModeloA");
    Automovil a("Marca1", "Modelo1", 2000, &m, &t);

    m.encender();
    a.arrancarAutomovil();
    a.apagarAutomovil();
    a.avanzarAutomovil(20);
}

void herencia() {
    Suma s(10, 15);
    Resta r(50, 40);

    cout << s.calcular() << endl;
    cout << r.calcular() << endl;
}

void herencia2() {
    Empleado* e = new Empleado("Juan", "12345678", "Av. Pepito 123", 1025, "2023/10/25");
    auto c = new Cliente("Maria", "11111111", "Ca. Quispe 100", "900000000");

    e->mostrar();
    c->mostrar();

    auto c2 = new Cliente(e, "987654321");

    c2->mostrar();
}

void composicion2() {
    WareHouse* w = new WareHouse("Ca. Hugo", 3, 3);

    w->addProductQuantity(1, 2, 1);
    w->addProductQuantity(0, 1, 2);
    w->addProductQuantity(2, 2, 3);

    cout << boolalpha << w->isSlotAvailable(2, 0) << endl;

    delete w;
}

void composicion3() {
    Hotel* h = new Hotel("Margarita");

    Habitacion* hab1 = new Habitacion(3, 1);
    Habitacion* hab2 = new Habitacion(3, 2);
    Habitacion* hab3 = new Habitacion(3, 3);
    Habitacion* hab4 = new Habitacion(3, 1);

    h->insertarHabitacion(hab1);
    h->insertarHabitacion(hab2);
    h->insertarHabitacion(hab3);
    h->insertarHabitacion(hab4);

    hab2->setDisponible(false);

    cout << h->calcularDisponibles(1) << endl;
    cout << h->calcularDisponibles(2) << endl;
    cout << h->calcularDisponibles(3) << endl;

    delete h;
}

void herencia3() {
    Book* b = new Book("Libro 1", 1, "123");
    NewsPaper* n = new NewsPaper("Periodico 1", 1, "987");

    b->show();
    n->show();

    delete b;
    delete n;
}

int main() {
//    composicion();
//    herencia();
//    herencia2();
//    composicion2();
//    composicion3();
//    herencia3();

    return 0;
}
