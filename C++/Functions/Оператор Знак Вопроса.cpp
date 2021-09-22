#include <iostream>
using namespace std;

int div_zero() {
    cout << "It is impossible to divide by 0 !!!\n";
    return 0;
}

int main() {
    int i, j, result;
    cin >> i >> j;
    
    result = j ? i/j : div_zero();
    
    cout << result;
    
    return 0;
}