/*
// Демонстрация использования функции - "друга"
#include <iostream>
using namespace std;

class MyClass {
    int a, b;
    public: 
    MyClass(int i, int j) { a = i; b = j; }
    friend int comDenom(MyClass x); // функция -"друг" класса MyClass
    
};

// функция comDenom не является членом ни одного класса

int comDenom(MyClass x)
{
    // функция имеет прямой доступ к членам класса
    int max = x.a < x.b ? x.a : x.b;
    
    for(int i = 2; i <= max; i++)
        if((x.a % i) == 0 && (x.b % i) == 0) return i;
        
    return 0;
}

int main()
{
    MyClass n(18, 111);
    
    if(comDenom(n))
        cout << "Общий множитель равен " << comDenom(n) << endl;
    else cout << "Общего множителя нет.\n";
    
    return 0;
}
*/

/*
// функциями - "друзьями" могут пользоваться сразу несколько классов.
#include <iostream>
using namespace std;

class Cylinder; // опережающее объявление

enum colors { red, green, blue };

class Cube {
    colors color;
    public:
        Cube (colors c) { color = c; }
        friend bool sameColor (Cube x, Cylinder y); // функция-"друг" класса Cube
        
};

class Cylinder{
    colors color;
    public:
        Cylinder(colors c) { color = c; }
        friend bool sameColor(Cube x, Cylinder y); // функция-"друг" и класса Cylinder
        
};

bool sameColor(Cube x, Cylinder y)
{
    if(x.color == y.color) return true;
    else return false;
}

int main()
{
    Cube cube1 (red);
    Cube cube2 (green);
    Cylinder cyl (green);
    
    if(sameColor(cube1, cyl))
        cout << "Объекты cube1 и cyl одинакового цвета.\n";
    else cout << "Объекты cube1 и cyl разного цвета.\n";
    
    if (sameColor(cube2, cyl))
        cout << "Объекты cube2 и cyl одинакового цвета.\n";
    else cout << "Объекты cube2 и cyl разного цвета.\n";
    
    return 0;
}
*/

// функция может быть членом одного класса и одновременно "другом" другого
#include <iostream>
using namespace std;

class Cylinder;

enum colours { red, green, blue } ;

class Cube {
    colours color;
    public: 
        Cube(colours c) { color = c; }
        bool sameColor (Cylinder y);
        
};

class Cylinder {
    colours color;
    public:
        Cylinder(colours c) { color = c; }
        friend bool Cube::sameColor(Cylinder y);
        
};

bool Cube::sameColor(Cylinder y) {
    if(color == y.color) return true;
    else return false;
}

int main()
{
    Cube cube1 (red);
    Cube cube2 (green);
    Cylinder cyl (green);
    
    if (cube1.sameColor(cyl))
        cout << "Объекты cube1 и cyl одинакового цвета.\n";
    else cout << "Объекты cube1 и cyl разного цвета.\n";
    
    if (cube2.sameColor(cyl))
        cout << "Объекты cube2 и cyl одинакового цвета.\n";
    else cout << "Объекты cube2 и cyl разного цвета.\n";
    
    return 0;
}

