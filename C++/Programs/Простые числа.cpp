#include <iostream>
using namespace std;

int main() {
    int c = 0;
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (i % j == 0) c++;
        }
        if (c == 2) cout << i << "\n";
        c = 0;
    }
    return 0;
}
