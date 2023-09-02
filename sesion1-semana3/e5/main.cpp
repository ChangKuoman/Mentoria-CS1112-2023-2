#include <iostream>
using namespace std;

int main() {

    int x;
    cout << "Ingrese un numero:";
    cin >> x;

    if (x < 0) {
        cout << "Es tramposo" << endl;
    }
    else if (x < 100 and x % 3 == 0 and x % 6 != 0) {
        cout << "Es tramposo" << endl;
    }
    else if (x >= 100 and x % 10 == 1) {
        cout << "Es tramposo" << endl;
    }
    else {
        cout << "No es tramposo" << endl;
    }

    return 0;
}
