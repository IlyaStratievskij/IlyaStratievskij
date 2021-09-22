#include <iostream>
#include <clocale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    string key, str;
    int i, j, k;

    cout << "Enter messenger: ";
    getline(cin, str);
    cout << "Enter key: ";
    cin >> key;

    for (i = 0; i < str.length(); i++) str[i] = toupper(str[i]);
    for (i = 0; i < key.length(); i++) key[i] = toupper(key[i]);

    int key_code[key.length()], str_code[str.length()];

    char arr[26][26];

    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++)
            arr[i][j] = 65 + j;
    }

    for (k = 1; k < 26; k++) {
        for (j = k; j < 26; j++) {
            char temp = arr[j][0];
            for (i = 0; i < 25; i++)
                arr[j][i] = arr[j][i+1];
            arr[j][25] = temp;
        }
    }

    k = 0;
    int s = 0;
    for(i = 0; i < key.length(); i++) {
        if (!isalpha(key[i])) s++;
        for(j = 0; j < 26; j++)
            if (arr[0][j] == key[i]) { key_code[k] = j; k++; break; }
    }

    int len_key = sizeof(key_code)/sizeof(int) - s;

    k = 0, s = 0;
    for(i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) s++;
        for(j = 0; j < 26; j++)
            if (arr[0][j] == str[i]) { str_code[k] = j; k++; break;  }
    }

    int len_str = sizeof(str_code)/sizeof(int) - s;

    char messenge[len_str];

    i = 0;
    while (i < len_str) {
        for (int j = 0; j < len_key; j++) {
            messenge[i] = arr[key_code[j]][str_code[i]];
            i++;
            if (i == len_str) goto next;
        }
    }
    next:

    cout << "Your coding messenge: ";
    for (i = 0; i < len_str; i++)
        cout << messenge[i] << " ";

    /*for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }*/
    return 0;
}
