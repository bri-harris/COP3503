#include <iostream>
using namespace std;

class Vect3 {
    float _x, _y, _z;

public:
    Vect3(float x = 0, float y = 0, float z = 0) {
        _x = x;
        _y = y;
        _z = z;
    }


bool operator==(const Vect3& other) {
    return (_x == other._x &&
            _y == other._y &&
            _z == other._z);
}
};

int main() {
    Vect3 a;
    Vect3 b;
    Vect3 c(1, 1, 1);

    cout << "pt a == pt b? " << (a == b) << endl;
    cout << "pt a == pt c? " << (a == c) << endl;
    cout << "pt b == pt c? " << (b == c) << endl;

    return 0;
}
