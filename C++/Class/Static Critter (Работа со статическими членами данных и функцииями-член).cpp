// Программа Static Critter
// Демонстрирует работу со статическими членами данных и функциями-членами

#include <iostream>

using namespace std;

class Critter 
{
    public:
        static int s_Total; // объявление статической переменной-члена
        // Общее кол-во существующих объектов Critter
        Critter(int hunger = 0);
        static int GetTotal(); // прототип статической функциями-членами
    private:
    int m_Hunger;
};

int Critter::s_Total = 0; // инициализация статической переменной-члена

Critter::Critter(int hunger):
m_Hunger(hunger)
{
    cout << "A critter has been born!" << endl;
    ++s_Total;
}

int Critter::GetTotal() // определение статической функциями-членами
{
    return s_Total;
}

int main() 
{
    cout << "The total number of crittes is: ";
    cout << Critter::s_Total << "\n\n";
    Critter crit1, crit2, crit3, crit4;
    cout << "\nThe total number of critters is: ";
    cout << Critter::GetTotal() << endl;
    
    return 0;
}
