#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long double a;
    a = atan(1) * 4;
    cout << setprecision(48) << fixed;
    cout << a;
    return 0;
}