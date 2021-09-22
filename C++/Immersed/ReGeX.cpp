#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
/*  
    // regex_match
    string str = "its string object with words"; // основная строка
    cmatch result; // хранит результат работы метода regex_match
    regex regular("([\\w\\s]*)"); // хранит регулярное выражение, которое имеет определенное правило ([a-z ]*)
    
    if (regex_match(str.c_str(), result, regular))
        cout << "true\n";
        
    for (int i = 0; i < result.size(); i++)
        cout << result[i++] << endl;
    
*/

// Ввод email
    /*
    // ПРИМЕР regex_match
    string str = "email@host.ru";
    cmatch result;
    regex regular ("([\\w-]+)"
                   "(@)"
                   "([\\w-]+)"
                   "(\.)"
                   "([a-z]{2,5})");
    
    if (regex_match(str.c_str(), result, regular))
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    */
    
    // ПРИМЕР regex_search и regex_replace
    string str = "MyEmail: email@host.ru LoLoL";
    cmatch result;
    regex regular ("([\\w-]+)"
                   "(@)"
                   "([\\w-]+)"
                   "(\.)"
                   "([a-z]{2,5})");
    
    if (regex_search(str.c_str(), result, regular))
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    
    cout << regex_replace(str.c_str(), regular, "---lulz---");
    
    return 0;
}
