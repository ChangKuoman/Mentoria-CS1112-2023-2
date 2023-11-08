#include <iostream>
#include <vector>
using namespace std;

void imprimir_algo(){
    cout << "Algo" << endl;
}

void imprimir_algo(int a) {
    cout << a << endl;
}

void imprimir_algo(char a) {
    cout << "El valor es: " <<a << endl;
}

class Text {
public:
    string value;
    Text(string t): value(t) {}
};

int operator+(Text cadena, int value) {
    // lógica
    return value + cadena.value.size();
}

Text operator+(Text cadena, Text otro) {
    // lógica
    return Text(cadena.value + otro.value);
}

void ejemplo1() {
    // sobrecarga de funciones
    imprimir_algo();
    imprimir_algo(45);
    imprimir_algo('y');
    // sobrecarga de operadores
    // 1. Unarios <-
    //    x++;
    // 2. Binarios <-
    //    x + y
    // 3. Terciario: ? :

    Text t("hola");
    Text t2("gato");
    // int + string
    cout << (t + 8) << endl;
    cout << (t + t2).value << endl;
}

class Persona {
private:
    string name;
    int edad;
public:
    Persona(string n, int e): name(n), edad(e) {}

    int operator+(Persona otro) {
        return edad + otro.edad;
    }

    int getEdad() {
        return edad;
    }

    void operator+(int n) {
        edad = edad + n;
    }

    friend ostream& operator<<(ostream& os, const Persona& p);
    friend class D;
};

class D {
private:

public:
    void algo(Persona p) {
        cout << p.name << endl;
    }
};

ostream& operator<<(ostream& os, const Persona& p) {
    cout << "--- Persona ---" << endl;
    cout << "Nombre: " << p.name << endl;
    cout << "Edad: " << p.edad << endl;
    return os;
}

void ejemplo2() {
    Persona p("juan", 15);
    Persona p2("pepe", 30);

    cout << p + p2 << endl;
    p + 8;
    cout << p.getEdad() << endl;

    cout << p << " Hola" << endl;

    D daaa;
    daaa.algo(p);
}

// paramétrico

template <typename T, typename U>
T algo(T a, U b) {
    cout << b << endl;
    return a + 10;
}

void ejemplo3() {
    cout << algo(15, "string") << endl;
    cout << algo(15.05, true) << endl;
}

class Animal {
protected:
    double peso;
    double altura;
public:
    Animal(double p, double a): peso(p), altura(a) {}
    virtual void imprimir()=0;
};

class Perro: public Animal {
private:
    string nombre;
public:
    Perro(double p, double a, string n): Animal(p, a), nombre(n) {}
    void imprimir() {
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
        cout << "Nombre: " << nombre << endl;
    }
};

class Gato: public Animal {
private:
    int edad;
public:
    Gato(double p, double a, int e): Animal(p, a), edad(e) {}
    void imprimir() {
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
        cout << "Edad: " << edad << endl;
    }
};

void ejemplo4() {
    // inclusion -> herencia
    Perro p(20.5, 20.4, "firulais");
    Gato g(15.4, 16.8, 3);

    p.imprimir();
    g.imprimir();
}

class Pizza {
private:
    string tipo;
    string tamano;
    double precio;
public:

    Pizza(string ti, string ta, double pre): tipo(ti), tamano(ta), precio(pre) {}
    string getTipo() {
        return tipo;
    }
    string getTamano() {
        return tamano;
    }
    double getPrecio() {
        return precio;
    }
};

class Cliente {
private:
    string codigo;
public:
    Cliente (string c): codigo(c) {}
    string getCodigo() {
        return codigo;
    }
};

class Pedido {
private:
    vector<Pizza*> pizzas;
    Cliente* cliente;
public:
    Pedido() {}
    void asignarCliente(Cliente* c) {
        cliente = c;
    }
    void agregarPizza(Pizza* p) {
        pizzas.push_back(p);
    }
    friend ostream& operator<<(ostream& os, Pedido* p) {
        os << "Cliente: " << p->cliente->getCodigo() << endl;
        int contador = 0;
        for (auto iter: p->pizzas) {
            os << "Pizza " << ++contador << ": " << endl;
            os << "Tamano: " << iter->getTamano() << endl;
            os << "Tipo: " << iter->getTipo() << endl;
            os << "Precio: " << iter->getPrecio() << endl;
        }
        return os;
    }
    double get_precio() {
        double temp = 0;
        for (auto iter: pizzas) {
            temp += iter->getPrecio();
        }
        return temp;
    }
};

void ej1() {
    auto c = new Cliente("1");
    auto p0 = new Pizza ("hawaiana", "personal", 10);
    auto p1 = new Pizza ("hawaiana", "familiar", 10);
    auto p2 = new Pizza ("napolitana", "personal", 10);
    auto p3 = new Pizza ("margarita", "personal", 10);

    auto pedido = new Pedido();
    pedido->asignarCliente(c);
    pedido->agregarPizza(p0);

    auto pedido1 = new Pedido();
    pedido1->asignarCliente(c);
    pedido1->agregarPizza(p1);

    auto pedido2 = new Pedido();
    pedido2->asignarCliente(c);
    pedido2->agregarPizza(p2);
    pedido2->agregarPizza(p3);

    cout << pedido << endl;
    cout << pedido1 << endl;
    cout << pedido2 << endl;

    // OPCIONAL
    vector<Pedido*> pedidos;
    vector<string> tipos_pizza = {"hawaiana", "napolitana", "margarita"};
    vector<string> tamano_pizza = {"personal", "familiar"};

    for (int i = 0; i < 20; i++) {
        // crear pedido
        auto pedido_temp = new Pedido();
        pedido_temp->asignarCliente(new Cliente(to_string(rand()%1000)));
        int n = rand()%5 + 1;
        for (int j = 0; j < n; j++) {
            pedido_temp->agregarPizza(new Pizza(tipos_pizza[rand()%3], tamano_pizza[rand()%2], rand()%20));
        }
        pedidos.push_back(pedido_temp);
    }

    int importe_total = 0;
    for (auto iter: pedidos) {
        cout << iter << endl;
        importe_total += iter->get_precio();
    }
    cout << "IMPORTE TOTAL: " << importe_total << endl;
}

int main() {
    srand(time(nullptr));
//    ejemplo1();
//    ejemplo2();
//    ejemplo3();
//    ejemplo4();
//    ej1();
    return 0;
}
