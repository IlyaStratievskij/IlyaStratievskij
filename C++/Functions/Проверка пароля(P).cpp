#include <iostream>
#include <cstring>
using namespace std;

bool paroli(char *str, int n) {
    char s[80];
    strcpy(s, "iluha");
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (*str != s[i]) c++;
        str++;
    }
    return (c == 0);
}

int main() {
    char str[80];
    cin.get(str, 80);
    int i = strlen(str);
    if (paroli(str, i)) cout << "Пароль верен";
    else cout << "Пароль не верен";
    return 0;
}