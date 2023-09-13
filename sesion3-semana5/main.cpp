#include <iostream>
#include <random>
using namespace std;

void p1() {
    // ingresar el dato
    int n;
    cout << "Numero de 4 digitos:";
    cin >> n;

    for (int i = 1000; i <= n; i++) {

        // usando strings
        string numero = to_string(i);
        int suma_de_digitos = int(numero[0] - '0') + int(numero[1] - '0') + int(numero[2] - '0') + int(numero[3] - '0');

        // usando division
        int temporal = i;
        int suma = 0;
        while (temporal > 0) {
            suma += temporal % 10;
            temporal /= 10;
        }

        cout << i << " " << suma << " ";

        if (suma % 2 == 0) {
            if (i % 10 == 0) {
                cout << "Lun - Mir - Vie - Sab y Dom" << endl;
            }
            else {
                cout << "Lun - Mir - Vie" << endl;
            }
        }
        else {
            cout << "Mar - Jue" << endl;
        }

    }
}

void sumar_angulos(int& grados, int& minutos, int& segundos, int i_g, int i_m, int i_s) {
    cout << grados << " " << minutos << " " << segundos << endl;
    cout << i_g << " " << i_m << " " << i_s << endl;
    cout << "--------------------------" << endl;

    segundos += i_s;
    if (segundos >= 60) {
        minutos += 1;
        segundos -= 60;
    }

    minutos += i_m;
    if (minutos >= 60) {
        grados += 1;
        minutos -= 60;
    }

    grados += i_g;

    cout << grados << " " << minutos << " " << segundos << endl;
}

void p2() {
    int cant_angulos;
    do {
        cout << "Numero de angulos [mayor a 3]:";
        cin >> cant_angulos;
    } while (cant_angulos <= 3);

    int grados = 0, minutos = 0, segundos = 0;
    int i_g, i_m, i_s;

    for (int i = 0; i < cant_angulos; i++) {
        cout << "Ingrese angulo " << i + 1 <<":";
        cin >> i_g >> i_m >> i_s;
        sumar_angulos(grados, minutos, segundos, i_g, i_m, i_s);
    }
}

void p3() {
    int n1, n2;
    do {
        cout << "Numero de casilleros del arreglo 1:";
        cin >> n1;
    } while (n1 < 5 ||  n1 > 20);

    do {
        cout << "Numero de casilleros del arreglo 2:";
        cin >> n2;
    } while (n2 < 5 ||  n2 > 20);

    int arreglo1[n1], arreglo2[n2], arreglo3[n1 + n2];

    for (int i = 0; i < n1; i++) {
        arreglo1[i] = (rand() % 50) + 1;
        cout << arreglo1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n2; i++) {
        arreglo2[i] = (rand() % 50) + 1;
        cout << arreglo2[i] << " ";
    }
    cout << endl;
    int k=0;
    if (n1 > n2) {
        for (int i=0; i<n2; i++) {
            arreglo3[k++] = arreglo1[i];
            arreglo3[k++] = arreglo2[i];
        }
        for (int i=n2; i<n1; i++) {
            arreglo3[k++] = arreglo1[i];
        }
    }
    else {
        // n2 > n1
        for (int i=0; i<n1; i++) {
            arreglo3[k++] = arreglo1[i];
            arreglo3[k++] = arreglo2[i];
        }
        for (int i=n1; i<n2; i++) {
            arreglo3[k++] = arreglo2[i];
        }
    }

    for (int i = 0; i < n1 + n2; i++) {
        cout << arreglo3[i] << " ";
    }
    cout << endl;
}

void p4() {
    char p1, p2;
    double a1, a2;
    double h1, h2;
    cout << "Planeta 1:";
    cin >> p1;
    cout << "Angulo 1:";
    cin >> a1;
    cout << "Planeta 2:";
    cin >> p2;
    cout << "Angulo 2:";
    cin >> a2;
    // PASO 1: sexagesimales a radianes
    a1 = a1 / 180.0 * 3.14159265;
    a2 = a2 / 180.0 * 3.14159265;
    // PASO 2: UA de c/planeta
    switch (p1) {
        case 'M':
            h1 = 0.39;
            break;
        case 'V':
            h1 = 0.72;
            break;
        case 'T':
            h1 = 1.00;
            break;
        case 'm':
            h1 = 1.52;
            break;
        case 'C':
            h1 = 2.77;
            break;
        case 'J':
            h1 = 5.2;
            break;
        case 'S':
            h1 = 9.58;
            break;
        case 'N':
            h1 = 30.1;
            break;
        case 'P':
            h1 = 39.3;
            break;
        case 'E':
            h1 = 96.4;
            break;
    }
    switch (p2) {
        case 'M':
            h2 = 0.39;
            break;
        case 'V':
            h2 = 0.72;
            break;
        case 'T':
            h2 = 1;
            break;
        case 'm':
            h2 = 1.52;
            break;
        case 'C':
            h2 = 2.77;
            break;
        case 'J':
            h2 = 5.2;
            break;
        case 'S':
            h2 = 9.58;
            break;
        case 'N':
            h2 = 30.1;
            break;
        case 'P':
            h2 = 39.3;
            break;
        case 'E':
            h2 = 96.4;
            break;
    }

    // PASO 3: hallar (x1, y1) y (x2, y2)
    double x1, x2, y1, y2;

    x1 = h1 * cos(a1);
    y1 = h1 * sin(a1);
    x2 = h2 * cos(a2);
    y2 = h2 * sin(a2);

    // PASO 4: distancia euclidiana
    double resultado = sqrt(
            pow(x1 - x2, 2) +
            pow(y1 - y2, 2)
    );

    cout << "La distancia entre dos planetas es " << resultado << " UA." << endl;
}

void p5() {
    int inicio, final;
    cout << "Ingrese pagina inicial:";
    cin >> inicio;
    cout << "Ingrese pagina final:";
    cin >> final;

    bool encontrado = false;
    int encontrado_n, lado;
    while (encontrado == false) {
        cout << "Por favor, abra el diccionario en la pagina " << (inicio + final) / 2 << endl;
        cout << "¿Su palabra se encuentra en esta pagina? si 1, no 2";
        cin >> encontrado_n;
        if (encontrado_n == 1) {
            encontrado = true;
            cout << "Palabra encontrada!" << endl;
        }
        else {
            cout << "¿Su palabra se encuentra a la derecha 2 o a la izquierda 1?";
            cin >> lado;
            if (lado == 1) { // izq
                final = (inicio + final) / 2;
            }
            else { // der
                inicio = (inicio + final) / 2;
            }
        }
    }
}

void p6() {
    int cant_viajeros_siguen = 4, i = 1, nro_viajero, quedarse;
    string nombre_pueblo;
    char abandonar;
    bool koji = true, abdiel = true, bianca = true, eneas = true;
    string u_koji, u_abdiel, u_bianca, u_eneas;
    string *u_iraida = &u_eneas;
    while (cant_viajeros_siguen > 1) {
        cout << "Viaje " << i << endl;
        cout << "Ingrese el nombre del pueblo " << i;
        cin >> nombre_pueblo;

        cout << "Alguno de los guerreros desea abandonar el viaje? (S/N):";
        cin >> abandonar;
        if (abandonar == 'S') {
            cant_viajeros_siguen--;
            cout << "Elija un guerrero:" << endl;
            if (koji) {
                cout << "1. Koji\n";
            }
            if (abdiel) {
                cout << "2. Abdiel\n";
            }
            if (bianca) {
                cout << "3. Bianca\n";
            }
            if (eneas) {
                cout << "4. Eneas\n";
            }
            cin >> nro_viajero;

            cout << "Desea quedarse (1) o volver (2)?";
            cin >> quedarse;

            switch (nro_viajero) {
                case 1:
                    koji = false;
                    u_koji = quedarse == 1 ? nombre_pueblo : "Pueblo Reloj";
                    break;
                case 2:
                    abdiel = false;
                    u_abdiel = quedarse == 1 ? nombre_pueblo : "Pueblo Reloj";
                    break;
                case 3:
                    bianca = false;
                    u_bianca = quedarse == 1 ? nombre_pueblo : "Pueblo Reloj";
                    break;
                case 4:
                    eneas = false;
                    u_eneas = quedarse == 1 ? nombre_pueblo : "Pueblo Reloj";
                    break;
            }
        }
        else {
            // abandonar == 'N'
            continue;
        }
    }

    if (koji) {
        cout << "Koji está viajando por el mundo" << endl;
    } else {
        cout << "Koji está en " << u_koji << endl;
    }

    if (abdiel) {
        cout << "Abdiel está viajando por el mundo" << endl;
    } else {
        cout << "Abdiel está en " << u_abdiel << endl;
    }

    if (bianca) {
        cout << "Bianca está viajando por el mundo" << endl;
    } else {
        cout << "Bianca está en " << u_bianca << endl;
    }

    if (eneas) {
        cout << "Eneas está viajando por el mundo" << endl;
        cout << "Iraida está viajando por el mundo" << endl;
    } else {
        cout << "Eneas está en " << u_eneas << endl;
        cout << "Iraida está en " << *u_iraida << endl;
    }

    cout << "Y vivieron felices para siempre" << endl;
}
int main() {
    srand(time(nullptr));

    // PUNTEROS
    int valor = 150;
    int *puntero = &valor;

    cout << *puntero << endl;

    int *puntero_heap = new int;
    *puntero_heap = 40;

    cout << *puntero_heap << endl;

    int *puntero_array = new int[50];

    delete []puntero_array;
    delete puntero_heap;
    return 0;
}
