// Демонстрация использования объединения 
/*
#include <iostream>

using namespace std;

union u_type {
    u_type (short int a) { i = a; }
    u_type (char x, char y) { ch[0] = x; ch[1] = y; }
    
    void showchars() {
        cout << ch[0] << " " << ch[1] << endl;
    }
    
    short int i;   // эти члены данных объединения
    char ch[2];    // разделяют одну и ту же область памяти.
};

int main() {
    u_type u (1000);
    u_type u2 ('X', 'Y');
    
    // Данные в объекте типа u_type можно использовать в 
    // качестве целочисленного значения или двух символов.
    cout << "Объединение u в качестве целого числа: ";
    cout << u.i << endl;
    cout << "Объединение u в качестве двух символов: ";
    u.showchars();
    
    cout << "Объединение u2 в качестве целого числа: ";
    cout << u2.i << endl;
    cout << "Объединение u2 в качестве двух символов: ";
    u2.showchars();
}
*/

// АНОНИМНОЕ ОБЪЕДИНЕНИЕ 
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    union {
        long l;
        double d;
        char s[4];
    };
    
    // обращение выполняется напрямую 
    l = 100000;
    cout << l << " ";
    d = 123.2342;
    cout << d << " ";
    strcpy(s, "hi");
    cout << s;
}
