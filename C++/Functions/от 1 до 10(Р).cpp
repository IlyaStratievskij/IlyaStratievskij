#include <iostream>
using namespace std;

int f(int n) {
   static int i = 1;
   cout << i;
   i++;
   if (n == 1) return 0;
   else return f(n - 1);
}

int main() {
    f(10);
}
