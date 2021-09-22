#include <iostream>
using namespace std;

int main() {
    double a;
    char z;
    cin >> a;
    while (z != '=') {
         double i;
         cin >> z;
         if (z == '=') break;
         cin >> i;
         if (z == '+') a = a + i;
         else if (z == '-') a = a - i;
         else if (z == '*') a = a * i;
         else if (z == '/') a = a / i;
        } ;
        
    cout << a;
    
    return 0;
}