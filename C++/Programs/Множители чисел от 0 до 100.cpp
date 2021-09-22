#include <iostream>
using namespace std;

int main() {
    for (int i = 2; i <= 100; i++) {
        cout << "Множители числа " << i <<" : ";
        for (int j = 2; j <= i; j++) {
            if ((i % j) == 0) cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}