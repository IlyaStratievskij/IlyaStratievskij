#include <iostream>
using namespace std;

int main() {
    char choice;
    
    cout << "Справка по инструкции :\n" << "1. if\n" << "2. switch\n" << "Выберите вариант справки : ";
    cin >> choice;
    
    cout << "\n";
    
    switch (choice) {
        case '1' :
        cout << "Синтаксис инструкции if :\n\n" << "if (условие) инструкция;\n" << "else инструкция;\n";
        break;
        case '2' :
        cout << "Синтаксис инструкции switch :\n\n";
        cout << "switch (выражение) {\n";
        cout << "   case константа :\n";
        cout << "      последовательность инструкций\n";
        cout << "      break;\n";
        cout << "   // ...\n";
        cout << "}";
        break;
        default : 
        cout << "Такого варианта нет.\n";
    }
    
    return 0;
}