#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int>::const_iterator iter;
    set <int> s;
    vector <string> si;
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        int y;
        cin >> y;
        if (s.find(y) == s.end()) si.push_back("NO");
        else si.push_back("YES");
        s.insert(y);
    }
    
    for (int i = 0; i < n; i++) {
        cout << si[i] << endl;
    }
}