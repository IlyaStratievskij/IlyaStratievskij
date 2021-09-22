#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
    return hypot(a.first, a.second) < hypot(b.first, b.second);
}

int main() {
    int n;
    cin >> n;
    vector <pair <int, int >> para(n);
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        para[i] = {x, y};
        
    }
    
    sort (para.begin(), para.end(),cmp);
    
    for(auto now : para) {
        cout << now.first << " " << now.second << endl;
    }
    
}