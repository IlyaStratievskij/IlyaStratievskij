#include <iostream>
using namespace std;

void f(int x) {
    cout << "in function f(int): " << x << endl;
}

void f(double x) {
    cout << "in function f(double): " << x << endl;
}

int main() {
    int a = 12;
    short b = 99;
    double c = 12.3;
    float d = 11.2F;
    
    f(a);
    f(b);
    f(c);
    f(d);
    
    return 0;
}