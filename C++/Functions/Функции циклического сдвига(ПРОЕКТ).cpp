/* Проект 

   Функции циклического сдвига вправо и влево для байтовых значений
*/
#include <iostream>
using namespace std;

unsigned char rrotate(unsigned char val, int n);
unsigned char lrotate(unsigned char val, int n);
void show_binary(unsigned int u);

int main() {
    char ch;
    cin >> ch;
    
    cout << "Original value in binary:\n";
    show_binary(ch);
    
    cout << "The result of an 8-fold cyclic shift to the right:\n";
    for (int i = 0; i < 8; i++) {
        ch = rrotate(ch, 1);
        show_binary(ch);
    }
    
    cout << "The result of an 8-fold cyclic shift to the left:\n";
    for (int i = 0; i < 8; i++) {
        ch = lrotate(ch, 1);
        show_binary(ch);
    }
    
    return 0;
}

// Функция циклического сдвига влево байта на n разрядов
unsigned char lrotate(unsigned char val, int n) {
    unsigned int t;
    
    t = val;
    
    for (int i = 0; i < n; i++) {
        t = t << 1;
        
        // Если выдвигаемый бит (8-й разряд значения t)
        //содержит единицу, то установливаем младший бит. 
        if (t & 256) t = t | 1; // Установливаем 1 на правом конце
     }
     
     return t; // Возвращаем младшие 8 бит
}

// Функция циклического сдвига вправо байта на n разрядов
unsigned char rrotate(unsigned char val, int n) {
    unsigned int t;
    
    t = val;
    
    // Сначала сдвигаем значение на 8 бит влево
    t = t << 8;
    
    for (int i = 0; i < n; i++) {
        t = t >> 1; // Сдвиг вправо на 1 разрядо
        
        /* После сдвига бита вправо на 1 разряд он становится 
        седьмым битом целочисленного значения t.
        Если 7-й бит равен 1, то нужно установить крайний слева бит */ 
        if (t & 128) t = t | 32768;
    }
    // Помещаем результат назад в младшие 8 бит значения t.
    t = t >> 8;
    
    return t;
}

// Отображаем биты, которые составляют байт
void show_binary(unsigned int u) {
    int t;
    
    for (t = 128; t > 0; t /= 2) {
        if (u & t) cout << '1';
        else cout << '0';
    }
    
    cout << endl;
}
