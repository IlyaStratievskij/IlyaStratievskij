#include <iostream>
#include <set>

using namespace std;

int main() {
    set <int> s;
    int n, x;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        int y;
        cin >> y;
        if (s.find(y) == s.end()) s.insert(y);
    }
    cout << s.size();
    
    return 0;
}