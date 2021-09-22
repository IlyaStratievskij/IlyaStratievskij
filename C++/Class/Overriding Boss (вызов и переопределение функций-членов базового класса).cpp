// Overriding Boss
// Демонстрация вызова и переопределения функций-членов базового класса

#include <iostream>

using namespace std;

class Enemy 
{
    public:
    Enemy(int damage = 10);
    // функция создаётся, как виртуальная для последующего переопределения
    void virtual Taunt() const;
    // функция создаётся, как виртуальная для последующего переопределения
    void virtual Attack() const;
    
    private:
    int m_Damage;
};

Enemy::Enemy(int damage):
m_Damage(damage)
{}

void Enemy::Taunt() const
{
    cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const
{
    cout << "Attack! Inflicts " << m_Damage << " damage points.";
}

class Boss : public Enemy
{
    public:
    Boss(int damage = 30);
    // использование ключевого слова virtual опционально
    void virtual Taunt() const;
    // использование ключевого слова virtual опционально
    void virtual Attack() const;
};

Boss::Boss(int damage):
Enemy(damage)
{}

void Boss::Taunt() const // переопределение функции-члена базового класса
{
    cout << "The boys says he will end your pitiful existence.\n";
}

void Boss::Attack() const // переопределение функции-члена базового класса
{
    Enemy::Attack(); // вызов функции-члена базового класса
    cout << " And laughs heartily at you.\n";
}

int main() 
{
    cout << "Enemy object:\n";
    Enemy anEnemy;
    anEnemy.Taunt();
    anEnemy.Attack();
    cout << "\n\nBoss object:\n";
    Boss aBoss;
    aBoss.Taunt();
    aBoss.Attack();
    
    return 0;
}























