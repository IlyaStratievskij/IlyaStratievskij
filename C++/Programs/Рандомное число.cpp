#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int c;
    cout << "Рандомное число будет в пределах от 0 до : ";
    cin >> c;
    srand(time(0));
    cout << rand() % c;
    return 0;
}