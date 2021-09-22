#include <iostream>
using namespace std;

int main() {
    char ch;
    for (int i = 0; i < 10; i++) {
        ch = 'A' + i;
        cout << ch;
        ch = ch | 32;
        cout << ch << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        ch = 'a' + i;
        cout << ch;
        ch = ch & 223;
        cout << ch << " ";
    }
    return 0;
}