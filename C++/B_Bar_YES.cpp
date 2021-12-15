#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m;
    cin.ignore(32767, '\n');
    string kokteli[n];
    for (int i = 0; i < n; i++)
        getline(cin, kokteli[i]);
        
    cin >> k;
    string name;
    int len;
    char symb;
    int lenGlass = n - 2;
    for (int i = 0; i < k; i++) {
        cin >> name >> len >> symb;
        int lenGlass_Len = lenGlass - len;
        for (; lenGlass > lenGlass_Len; lenGlass--) {
            int j = 0;
            
            while (kokteli[lenGlass][j] != '\\' 
                && kokteli[lenGlass][j] != '|' 
                && kokteli[lenGlass][j] != '/') j++;
            j++;
            while (kokteli[lenGlass][j] != '\\' 
                && kokteli[lenGlass][j] != '|' 
                && kokteli[lenGlass][j] != '/') {
                    kokteli[lenGlass][j] = symb;
                    j++;
                }
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << kokteli[i] << endl;
        
    return 0;
}