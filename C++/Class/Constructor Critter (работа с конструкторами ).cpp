// программа Constructor Critter
// Демонстрирует работу с конструкторами

#include <iostream>

using namespace std;

class Critter // определение нового класса - определяет новый тип Critter
{
    public:
    int m_Hunger; // член данных
    Critter(int hunger = 0); // прототип конструктора
    void Greet(); // прототип члена функции
};

Critter::Critter(int hunger) // определение конструктора
{
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
}

void Critter::Greet()
{
    cout << "Hi, I'm a critter. My hunger level is " << m_Hunger << endl;
}

int main() 
{
    Critter crit(7);
    crit.Greet();
    
    return 0;
}
