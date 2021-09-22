#include <iostream>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    
    for (int i = 0; i < k; i++) {
        int l, g;
        cin >> l >> g;
        for (int j = 0; j < n; j++) {
            if (a[j] >= l && a[j] <= g) a[j] = a[j] * 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) cout << '.';
        else cout << 'I';
    }
}