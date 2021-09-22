#include <iostream>
#include <string>
using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int * min(int *a, int *b) {
    if (*a < *b) return a;
    else return b;
}

char min(char a, char b) {
    if (tolower(a) < tolower(b)) return a;
    else return b;
} 

int main() {
    int i = 10, j = 22;
    cout << "char min = " << min('X', 'a') << endl;
    cout << "int min = " << min(9, 3) << endl;
    cout << "* int min = " << min(&i, &j);
    
    return 0;
}