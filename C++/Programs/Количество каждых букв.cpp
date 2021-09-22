#include <iostream>
#include <string>
using namespace std;

void printPosl(string str) {
    int n = str.length();
    for (int i = 0; i < n; i++) {
        int c = 1;
        while (i < n && str[i] == str[i + 1]) {
            c++;
            i++;
        }
        cout << str[i] << c;
    }
}

int main() {
    string a;
    cin >> a;
    printPosl(a);
    return 0;
}