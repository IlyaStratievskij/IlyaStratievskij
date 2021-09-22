#include <iostream>
using namespace std;

void show_binary(unsigned int u) {
    register int i;
    
    for (i = 128; i > 0; i /= 2) {
        if (u & i) cout << '1';
        else cout << '0';
    }
}

int main() {
    unsigned int u;
    cout << "Enter the number from 0 to 255: ";
    cin >> u;
    
    cout << "Binary number: ";
    show_binary(u);
    cout << endl;
    
    cout << "Addition to unit: ";
    show_binary(~u);
    
    return 0;
}