#include <iostream>

using namespace std;

class MyClass {
    int val;
    public:
    MyClass (int i) {
        val = i;
        cout << "Внутри конструктора.\n";
    }
    
    ~MyClass() { cout << "Разрушение объекта.\n"; }
    int getval() { return val; }
    void setval(int i) { val = i; } 
};

void display (MyClass &ob) {
    cout << ob.getval() << endl;
}

void change (MyClass &ob) {
    ob.setval(100);
    display(ob);
}

int main() {
    MyClass a(10);
    
    cout << "a до change(): ";
    display(a);
    cout << "\na в change(): ";
    change(a);
    cout << "\na после change(): ";
    display(a);
}