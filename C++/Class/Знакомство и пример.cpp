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
    
    int range;
    
    minivan.passengers = 7;
    minivan.fuelcap = 16;
    minivan.mpg = 21;
    
    range = minivan.fuelcap * minivan.mpg;
    
    cout << "Минифургон может перевести " << minivan.passengers 
    << " пассажиров на расстояние " << range << " километров." << "\n";
    
    return 0;
}
