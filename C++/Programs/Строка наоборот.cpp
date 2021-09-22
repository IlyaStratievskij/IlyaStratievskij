#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    char *start, *end;
    int len;
    char t;
    
    cout << "Введите исходную строку(желательно на английском): ";
    cin.get(str, 100);
    
    len = strlen(str);
    
    start = str;
    end = &str[len - 1];
    cout << endl << start << " " << end << endl;
    while (start < end) {
        t = *start;
        *start = *end;
        *end = t;
        
        start++;
        end--;
    }
    cout << "Строка после реверсирования: " << str << endl;
    
    return 0;
}