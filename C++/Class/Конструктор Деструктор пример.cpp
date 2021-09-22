#include <iostream>
using namespace std;

class MyClass {
    public:
    int x;
    
    MyClass();
    ~MyClass();
};

MyClass::MyClass() {
    x = 10;
}

MyClass::~MyClass() {
    cout << "Delete object...\n";
}

int main() {
    MyClass ob1;
    MyClass ob2;
    
    cout << ob1.x << " " << ob2.x << "\n";
    
    return 0;
}