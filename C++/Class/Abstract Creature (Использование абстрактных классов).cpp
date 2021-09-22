// Abstract Creature
// Демонстрация использование абстрактных классов

#include <iostream>

using namespace std;

class Creature // абстрактный класс
{
    public:
        Creature(int health = 100);
        virtual void Greet() const = 0; // частная виртуальная функция-член
        virtual void DisplayHealth() const;
    protected:
        int m_Health;
};

Creature::Creature(int health):
m_Health(health)
{}

void Creature::DisplayHealth() const
{
    cout << "Health: " << m_Health << endl;
}

class Orc : public Creature
{
    public:
    Orc(int health = 120);
    virtual void Greet() const;
};

Orc::Orc(int health):
Creature(health)
{}

void Orc::Greet() const
{
    cout << "The orc grunts hello.\n";
}

int main()
{
    Creature* pCreature = new Orc();
    pCreature->Greet();
    pCreature->DisplayHealth();

    return 0;
}
