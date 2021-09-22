#include <iostream>
using namespace std;

int main() {
    char choice; 
    
    do {
       cout << "Справка по инструкциям:\n";
       cout << "  1. if\n";
       cout << "  2. switch\n";
       cout << "  3. for\n";
       cout << "  4. while\n";
       cout << "  5. do-while\n";
       cout << "Выберите вариант справки: ";
       
       cin >> choice;
       
   } while ( choice < '1' || choice > '5');
   
   cout << "\n\n";
   
   switch (choice) {
       case '1':
       cout << "Инструкция if:\n\n";
       cout << "if (условие) инструкция;\n";
       cout << "else инструкция;\n";
       break;
       case '2':
       cout << "Инструкция switch:\n\n";
       cout << "switch (выражение) {\n";
       cout << "  case константа:\n";
       cout << "    последвательность инструкций\n";
       cout << "    break;\n";
       cout << "  // ...\n";
       cout << "}\n";
       break;
       case '3':
       cout << "Инструкция for:\n\n";
       cout << "for (инициализация; условие; инкремент)";
       cout << " инструкция;\n";
       break;
       case '4':
       cout << "Инструкция while:\n\n";
       cout << "while (условие) инструкция;\n";
       break;
       case '5':
       cout << "Инструкция do-while^\n\n";
       cout << "do {\n";
       cout << " инструкция;\n";
       cout << "} while (условие);\n";
       break;
   }
   return 0;
}