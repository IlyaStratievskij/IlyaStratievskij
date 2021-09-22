/* 
    Проект 8.2.
    
    Класс очереди для хранения символов
*/
#include <iostream>

using namespace std;

const int maxQsize = 100; // максимальное возможное число элементов, которое
                          // может храниться в очереди
                         
class Queue {
    char q[maxQsize]; // массив, на котором строится очередь
    
    int size; // реальный размер очереди
    
    int putloc, getloc; // индексы
    
    public:
    
    Queue(int len) {
        if(len > maxQsize) len = maxQsize;
        else if (len <= 0) len = 1;
        
        size = len;
        putloc=getloc=0;
    }
    
    // функция внесения элемента в очередь
    void put(char ch) {
        if (putloc == size) {
            cout << " -- Очередь заполнена.\n";
            return;
        }
        
        putloc++;
        q[putloc] = ch;
    }
    
    // функция считывания символа из очереди.
    char get() {
        if(getloc == putloc) {
            cout << " -- Очередь пуста.\n";
            return 0;
        }
        
        getloc++;
        return q[getloc];
    }
};

// демонастрация использования класса Queue
int main() {
    Queue bigQ(100);
    Queue smallQ(4);
    char ch;
    int i;
    
    cout << "Использование очереди bigQ для хранения алфавита.\n";
    for(i = 0; i < 26; i++)
        bigQ.put('A' + i);
        
    cout << "Содержимое очереди bigQ: ";
    for (i = 0; i < 26; i++) {
        ch = bigQ.get();
        if(ch != 0) cout << ch;
    }
    
    cout << "\n\n";
    
    cout << "Использование очереди smallQ для генерирования ошибок.\n";
    for(i = 0; i < 5; i++) {
        cout << "Попытка сохранилась " << (char) ('Z' - i);
        
        smallQ.put('Z' - i);
        
        cout << endl;
    }
    
    cout << endl;
    
    cout << "Содержимое очереди smallQ: ";
    for(i = 0; i < 5; i++) {
        ch = smallQ.get();
        
        if(ch != 0) cout << ch;
    }
    
    cout << "\n";
}
