#include <iostream>
using namespace std;

class Vehicle {
    public :
    int passengers;
    int fuelcap;
    
    int mpg;
};

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
    
    range1 = minivan.fuelcap * minivan.mpg;
    range2 = sportscar.fuelcap * sportscar.mpg;
    
    cout << "Минифургон может перевести " << minivan.passengers 
    << " пассажиров на расстояние " << range1 << " километров." << "\n";
    
    cout << "Спортивный автомобиль может перевести " << sportscar.passengers
    << " пассажира на расстояние " << range2 << " километров." << "\n";
    
    return 0;
}
