#include <iostream>
using namespace std;

void myswap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

int min_swap(int x, int y) {
    if (x < y) return x;
    else return y;
}

int main() {
    int x = 10, y = 20;
    cout << "before conversion x = " << x << ", y = " << y << endl;
    myswap(x, y);
    cout << "after conversion x = " << x << ", y = " << y << endl;
    cout << "minimal number = " << min_swap(x, y);
}