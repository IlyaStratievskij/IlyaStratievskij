// Перегрузка опреатора "+" с помощью функции-"дргуга"

#include <iostream>
using namespace std;

class ThreeD {
    int x, y, z;
public:
    ThreeD() { x = y = z = 0; }
    ThreeD(int i, int j, int k) { x = i; y = j; z = k; }
    
    // Здесь функция operator+() Объявлена "другом" класса
    // ThreeD. Обращаем внимание на необходимость
    // использования в этом случае двух параметров.
    friend ThreeD operator+(ThreeD op1, ThreeD op2);
    
    friend ThreeD operator+(ThreeD op1, int op2);
    friend ThreeD operator+(int op1, ThreeD op2);
    
    friend ThreeD operator++(ThreeD &op1);
    friend ThreeD operator++(ThreeD &op1, int notused);
    
    void show();
};

ThreeD operator+(ThreeD op1, ThreeD op2) {
    ThreeD temp;
    
    temp.x = op1.x + op2.x;
    temp.y = op1.y + op2.y;
    temp.z = op1.z + op2.z;
    
    return temp;
}

ThreeD operator+(ThreeD op1,int op2) {
    ThreeD temp;
    
    temp.x = op1.x + op2;
    temp.y = op1.y + op2;
    temp.z = op1.z + op2;
    
    return temp;
}

ThreeD operator+(int op1, ThreeD op2) {
    ThreeD temp;
    
    temp.x = op2.x + op1;
    temp.y = op2.y + op1;
    temp.z = op2.z + op1;
    
    return temp;
}

ThreeD operator++(ThreeD &op1) {
    op1.x++;
    op1.y++;
    op1.z++;
    return op1;
}

ThreeD operator++(ThreeD &op1, int notused){
    ThreeD temp = op1;
    
    op1.x++;
    op1.y++;
    op1.z++;
    return temp;
}

void ThreeD::show()
{
    cout << x << ", " << y << ", " << z << endl;
}

int main(){
    ThreeD a(1, 2, 3), b(10, 10, 10), c, b1;
    
    cout << "Исходные значения координат объекта а: ";
    a.show();
    cout << "Исходные значения координат объекта b: ";
    b.show();
    
    cout << endl;
    
    c = a + b;
    cout << "с = а + b: ";
    c.show();
    
    cout << endl;
    
    c = a + b + c;
    cout << "c = a + b + c: ";
    c.show();
    
    cout << endl;
    
    c = b = a;
    
    cout << "c после c = b = a: ";
    c.show();
    cout << "b после c = b = a: ";
    b.show();
    
    cout << endl;
    
    b1 = a + 10;
    cout << "b1 после b1 = a + 10: ";
    b1.show();
    
    cout << endl;
    
    b1 = 10 + a;
    cout << "b1 после b1 = 10 + a: ";
    b1.show();
    
    cout << "-----------Унарный оператор-----------\n";
    
    cout << "Исходные значения координат объекта а: ";
    a.show();
    a++;
    cout << "значения координат объекта a после а++: ";
    a.show();

    ++a;
    cout << "значения координат объекта a после ++a: ";
    a.show();
    
    cout << "Исходные значения координат объекта b: ";
    b.show();
    b = ++a;
    cout << "значения координат объекта b после b = ++a: ";
    b.show();
    b = a++;
    cout << "значения координат объекта b после b = a++: ";
    b.show();
    
    return 0;
}









