// программа Simple Critter
// Демонстрирует создание нового типа

#include <iostream>

using namespace std;

class Critter // определение нового класса - определяет новый тип Critter
{
    public:
    int m_Hunger; // член данных
    void Greet(); // прототип члена функции
};

void Critter::Greet()
{
    cout << "Hi, I'm a critter. My hunger level is " << m_Hunger << endl;
}

int main() 
{
    Critter crit1;
    Critter crit2;
    crit1.m_Hunger = 9;
    cout << "crit1's hunger level is " << crit1.m_Hunger << endl;
    crit2.m_Hunger = 3;
    cout << "crit2's hunger level is " << crit2.m_Hunger << endl;
    
    crit1.Greet();
    crit2.Greet();
    
    return 0;
}
