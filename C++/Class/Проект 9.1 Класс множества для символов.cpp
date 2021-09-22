/*
   Проект 9.1
   
   Класс множества для символов
*/

#include <iostream>
using namespace std;

const int MaxSize = 100;

class Set {
    int len; // количество членов
    char members[MaxSize]; // на этом массиве построено множество
    
    // функция find закрыта, так как она используется вне класса Set
    int find(char ch); // выполняет поиск элемента
    
public:
    Set() { len = 0; } // построение пустого множества
    
    int getLength() { return len; }
    
    void showset(); // отображает множество
    bool isMember(char ch); // проверка членства
    
    Set operator+(char ch); // добавление элемента
    Set operator-(char ch); // удаление элемента
    
    Set operator+(Set ob2); // объединение множеств
    Set operator-(Set ob2); // получение разности множеств
};

// функция возвращает индекс элемента, заданного параметром ch, или -1 если такой не найден
int Set::find(char ch) {
    int i;
    
    for(i = 0; i < len; i++) 
        if (members[i] == ch) return i;
        
    return -1;
}

// Отображение содержимого множества
void Set::showset() {
    cout << "{ ";
    for (int i = 0; i < len; i++) 
        cout << members[i] << " ";
    
    cout << "}\n";
}

/* функция возвращает значение true, если символ сh является членом множества
или значение false в обратном */ 
bool Set::isMember(char ch) {
    if (find(ch) != -1) return true;
    return false;
}

// добавление нового элемента в множество
Set Set::operator+(char ch) {
    Set newset;
    
    if(len == MaxSize) {
        cout << "множество заполнено!\n";
        return *this; // возвращает существующее множество
    }
    
    newset = *this; // дублирует существующее множество
    
    // Проверяет, существует ли уже в множестве такой элемента
    if (find(ch) == -1) {
        newset.members[newset.len] = ch;
        newset.len++;
    }
    return newset; // возвращает модифицированное множество
}

// Удаляем элемент из множества
Set Set::operator-(char ch) {
    Set newset;
    int i = find(ch);
    
    for (int j = 0; j < len; j++) 
        if(j != i) newset = newset + members[j];
        
    return newset;
}

// Объединение множеств
Set Set::operator+(Set ob2) {
    Set newset = *this; // копирует первое множество
    
    for (int i = 0; i < ob2.len; i++) 
        newset = newset + ob2.members[i];
        
    return newset;
}

Set Set::operator-(Set ob2) {
    Set newset = *this; // копирует первое множество
    
    for (int i = 0; i < ob2.len; i++) 
        newset = newset - ob2.members[i];
        
    return newset;
}

int main()
{
    // Создаём пустые множества
    Set s1;
    Set s2;
    Set s3;
    
    s1 = s1 + 'A';
    s1 = s1 + 'B';
    s1 = s1 + 'C';
    
    cout << "Множество s1 после добавления символов А В С: ";
    s1.showset();
    
    cout << endl;
    
    cout << "Тестирование членства с помощью функции isMember()\n";
    if(s1.isMember('B'))
        cout << "B - член множества s1.\n";
    else cout << "B - не член множества s1.\n";
    
    if(s1.isMember('T'))
        cout << "T - член множества s1.\n";
    else cout << "T - не член множества s1.\n";
    
    cout << endl;
    
    s1 = s1 - 'B';
    cout << "s1 после s1 = s1 - 'B': ";
    s1.showset();
    
    s1 = s1 - 'A';
    cout << "s1 после s1 = s1 - 'A': ";
    s1.showset();
    
    s1 = s1 - 'C';
    cout << "s1 после s1 = s1 - 'C': ";
    s1.showset();
    
    cout << endl;
    
    s1 = s1 + 'A';
    s1 = s1 + 'B';
    s1 = s1 + 'C';
    cout << "Множество s1 после добавления символов А В С: ";
    s1.showset();
    
    s2 = s2 + 'A';
    s2 = s2 + 'X';
    s2 = s2 + 'W';
    cout << "Множество s2 после добавления символов А X W: ";
    s2.showset();
    
    cout << endl;
    
    s3 = s1 + s2;
    cout << "s3 после s3 = s1 + s2: ";
    s3.showset();
    
    s3 = s3 - s1;
    cout << "s3 после s3 = s3 - s1: ";
    s3.showset();
    
    cout << "s2 после s2 = s2 - s2: ";
    s2 = s2 - s2;
    s2.showset();
    
    cout << endl;
    
    s2 = s2 + 'C';
    s2 = s2 + 'B';
    s2 = s2 + 'A';
    
    cout << "Множество s2 после добавления символов C B A: ";
    s2.showset();

    return 0;
}











