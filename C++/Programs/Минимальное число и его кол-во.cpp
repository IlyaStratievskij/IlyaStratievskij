#include <iostream>
#include <climits>
using namespace std;

int main() {
    int i;
    cin >> i;
    int h = i;
    int s = 0;
    int m = INT_MAX;
    
    while (i) {
        s++;
        i /= 10;
    }

    int iarray[s];
    for (int j = s - 1; j >= 0; j--) {
        iarray[j] = h % 10;
        h /= 10;
    }
    
    for (int j = 0; j < s; j++) {
        if(iarray[j] <= m) m = iarray[j];
    }

    int c = 0;
    for (int j = s - 1; j >= 0 ; j--) {
        if(iarray[j] == m) c++;
    }
    
    cout << "quantity = " << c << ", number = " << m;
}