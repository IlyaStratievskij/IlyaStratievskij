#include <iostream>
using namespace std;

int main() {
    again :
    int n;
    cin >> n;
    bool h = n >= 1984;
    if (h) {
        cout << n << " - год ";
        int year = n % 1984 % 12;
        int color = n % 1984 % 10;
        
        switch (color) {
            case 0:
            case 1:
            if (year == 2 || year == 3 || year == 4)  cout << "Зелёного";
            else cout << "Зелёной";
            break;
            case 2:
            case 3:
            if (year == 2 || year == 3 || year == 4)  cout << "Красного";
            else cout << "Красной";
            break;
            case 4:
            case 5:
            if (year == 2 || year == 3 || year == 4)  cout << "Жёлтого";
            else cout << "Жёлтой";
            break;
            case 6:
            case 7:
            if (year == 2 || year == 3 || year == 4)  cout << "Белого";
            else cout << "Белой";
            break;
            case 8:
            case 9:
            if (year == 2 || year == 3 || year == 4)  cout << "Чёрного";
            else cout << "Чёрной";
            break;
        }
        
        switch (year) {
            case 0:
            cout << " Крысы";
            break;
            case 1:
            cout << " Коровы";
            break;
            case 2:
            cout << " Тигра";
            break;
            case 3:
            cout << " Зайца";
            break;
            case 4:
            cout << " Дракона";
            break;
            case 5:
            cout << " Змеи";
            break;
            case 6:
            cout << " Лошади";
            break;
            case 7:
            cout << " Овцы";
            break;
            case 8:
            cout << " Обезьяны";
            break;
            case 9:
            cout << " Петуха";
            break;
            case 10:
            cout << " Собаки";
            break;
            case 11:
            cout << " Свиньи";
            break;
        }
    }
    else { cout << "Введите другой год: ";
    goto again; }
    
    return 0;
}