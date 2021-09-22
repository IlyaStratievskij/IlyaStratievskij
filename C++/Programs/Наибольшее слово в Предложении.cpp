#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int min = 0;
    string s;
    getline(cin, s);
    s = " " + s + " ";
    vector<int>dlina;
    for (int i = 0; i < s.size(); i++) {
        static int c = 0;
        if (isspace(s[i])) { 
            dlina.push_back(c);
            c = 0;
        }
        else c++;
    }
    
    for (int i = 0; i < dlina.size(); i++) {
        if (dlina[i] >= min) min = dlina[i];
    }
    
    int k = 0;
    for (int i = 0; i < dlina.size(); i++) {
        if (dlina[i] != min) k += dlina[i] + 1;
        else if (dlina[i] == min) break;
    }
    min += 1;

    s.erase(0, k);
    s.erase(min);
    cout << s;
}