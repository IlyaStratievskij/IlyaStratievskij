#include <iostream>

using namespace std;

class MyClass {
    int val;
    int copynumber;
    public:
    // Обычный конструктор
    MyClass(int i) {
        val = i;
        copynumber = 0;
        cout << "Внутри обычного конструктора.\n";
    }
    
    // Конструктор копии
    MyClass(const MyClass &obj) {
        val = obj.val;
        copynumber = obj.copynumber + 1;
        cout << "Внутри конструктора копии.\n";
    }
    
    ~MyClass() {
        if(copynumber == 0)
            cout << "Разрушение оригинального объекта.\n";
        else 
            cout << "Разрушение копии " << copynumber << endl;
    }
    
    int getval() { return val; }
};

void display(MyClass ob)
{
    cout << ob.getval() << endl;
}

int main() {
    MyClass a(10);
    
    display(a);
    
    return 0;
}

















