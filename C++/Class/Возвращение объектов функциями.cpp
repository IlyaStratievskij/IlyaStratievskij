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
    
    // Возвращение объекта.
    MyClass mkBigger() {
        MyClass o(val * 2);
        
        return o;
    }
};

void display (MyClass ob) {
    cout << ob.getval() << endl;
}

int main() {
   cout << "Перед созданием объекта а.\n";
   MyClass a(10);
   cout << "После создания объекта а.\n\n";
   
   cout << "Перед вызовом функции display().\n";
   display(a);
   cout << "После возвращения из функции display().\n\n";
   
   cout << "Перед вызовом функции mkBigger().\n";
   a = a.mkBigger();
   cout << "После возвращения из функции mkBigger().\n\n";
   
   cout << "Перед вторым вызовом функции display().\n";
   display(a);
   cout << "После возвращения из функции display().\n\n";
   
   return 0;
}