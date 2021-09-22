#include <iostream>
using namespace std;

class Vehicle { 
    public:
    int passengers; //количество пассажиров
    int fuelcap;  //вместимость топлива
    int mpg;   // расход горючего 
    
    int range();  // фун-ция вычисления пробега
};

int Vehicle::range() {
    return mpg * fuelcap;
}

int main() {
    Vehicle minivan;
    Vehicle sportscar;
    
    int range1, range2;
    
    minivan.passengers = 7;
    minivan.fuelcap = 16;
    minivan.mpg = 21;
    
    sportscar.passengers = 2;
    sportscar.fuelcap = 14;
    sportscar.mpg = 12;
    
    range1 = minivan.range();
    range2 = sportscar.range();
    
    cout << "Минифургон может перевезти " << minivan.passengers 
    << " пассажиров на расстояние " << range1 << " километров.\n";
    
    cout << "Спортивный автомобиль может перевезти " << sportscar.passengers
    << " пассажиров на расстояние " << range2 << " километров\n";
    
    return 0;
}