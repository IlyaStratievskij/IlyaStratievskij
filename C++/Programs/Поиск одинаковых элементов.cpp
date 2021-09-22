#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int a[10];
    int c = 1, b = 1;
    for (int i = 0; i < 10; i++) {
        a[i] = (rand() % 10);
    }
    cout << "Список значений: ";
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
          if (a[i] == a[j]) { c++;  
          a[j] = (rand() % 400) + 2000;}
        }
        if (c > 1) { cout << "Значение " << a[i] << " повторилось в списке " << c << " разa" <<endl;
        b++;
        a[i] = (rand() % 600) + 10000;}
        c = 1;
    }
    if (b < 2) cout << "Одинаковых значений нет";
    
    return 0;
}