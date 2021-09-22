#include <iostream>

using namespace std;

class MyClass {
    int x, y, z;
    public:
    MyClass(int a = 0, int b = 0, int c = 0) { x = a; y = b; z = c; }
    friend ostream &operator<<(ostream &stream, MyClass obj);
    friend istream &operator>>(istream &stream, MyClass &obj);
};

ostream &operator<<(ostream &stream, MyClass obj) {
    stream << obj.x << ", ";
    stream << obj.y << ", ";
    stream << obj.z << "\n";
    return stream;
}

istream &operator>>(istream &stream, MyClass &obj) {
    stream >> obj.x >> obj.y >> obj.z;
    return stream;
}

int main() {
    MyClass a(1, 2, 3), b(1, 1);
    cout << a << b;
    cin >> a;
    cout << a;
}
