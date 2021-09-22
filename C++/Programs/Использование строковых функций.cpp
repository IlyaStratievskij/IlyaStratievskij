#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char s1[80], s2[80];
    
    strcpy(s1, "C++");
    strcpy(s2, " - это мощный язык.");
    
    cout << "Длины строк: " << strlen(s1) << " " << strlen(s2) << "\n";
    
    if (!strcmp(s1, s2)) cout << "Эти строки равны.\n";
    else cout << "Эти строки не равны\n";
    
    strcat(s1, s2);
    cout << s1 << "\n";
    
    strcpy(s2, s1);
    cout << s1 << " и " << s2 << "\n";
    
    if (!strcmp(s1, s2)) cout << "Теперь строки s1 и s2 одинаковы.\n";
    
    return 0;
}