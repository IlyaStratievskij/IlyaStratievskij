#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char msg[15];
    cin.get(msg, 15);
    char key = 20;

    for (int i = 0; i < strlen(msg); i++) {
        msg[i] = msg[i] ^ key;
    }
    cout << msg << endl;
    
    for (int i = 0; i < strlen(msg); i++) {
        msg[i] = msg[i] ^ key;
    }
    cout << msg << endl;
}