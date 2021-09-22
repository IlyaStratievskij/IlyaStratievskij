#include <iostream>
using namespace std;

void show_binary(unsigned int u);

int main() {
    int i = 1, t;
    
    //сдвиг влево
    for (t = 0; t < 8; t++) {
        show_binary(i);
        i = i << 1; // сдвиг влево переменной i на 1 позицию
    }
    
    cout << endl;
    
    //сдвиг вправо
    for(t = 0; t < 8; t++) {
        i = i >> 1;
        show_binary(i); //сдвиг вправо i на 1 позицию
    }
    
    return 0;
}

void show_binary(unsigned int u) {
    int t;
    
    for(t = 128; t > 0; t /= 2) {
        if (u & t) cout << '1';
        else cout << '0';
    }
    cout << endl;
}