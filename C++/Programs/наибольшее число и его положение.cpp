#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main() {
    string i;
    getline(cin, i);
    int s = i.length();
    char m = CHAR_MIN;

    for (int j = 0; j < s; j++) {
        if (i[j] >= m) m = i[j];
    }

    int c = 1;
    for (int j = s - 1; ; j--) {
        if(i[j] != m) c++;
        else if (i[j] == m) break;
    }

    int k = 1;
    for (int j = 0; ; j++) {
        if(i[j] != m) k++;
        else if (i[j] == m) break;
    }

    cout << "place from the end = " << c << ", place from the begin = " << k << ", number = " << m;
}
