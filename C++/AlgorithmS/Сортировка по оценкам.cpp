#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct man {
    int number;
    string name;
    string surname;
};

bool cmp(man a, man b) {
    return a.number > b.number;
}

int main() {
    int n;
    cin >> n;
    vector <man> a(n);
    for (int i = 0; i < n; i++) {
        int t1, t2, t3, temp;
        string s_temp, s1_temp;
        cin >> s_temp >> s1_temp;
        cin >> t1 >> t2 >> t3;
        man struct_temp; // временная структура
        temp = t1 + t2 + t3; 
        struct_temp.number = temp;
        struct_temp.name = s_temp;
        struct_temp.surname = s1_temp;
        a[i] = struct_temp; // создание пары значение - номер
    }
    stable_sort(a.begin(), a.end(), cmp);
    //reverse(a.begin(), a.end());
    for (auto now : a) {
        cout << now.name << " " <<  now.surname << endl;
    }
    return 0;
}