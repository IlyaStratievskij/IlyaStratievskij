#include <iomanip>
#include <iostream>
//#include <stdlib.h>
//#include <unistd.h>
#include <windows.h>
using namespace std;

int hours;
int minutes;
int seconds;
void displayClock() {
    system("cls");
    cout << setfill(' ') << setw(50) << "           TIMER       \n";
    cout << setfill(' ') << setw(55) << "--------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec | " << endl;
    cout << setfill(' ') << setw(55) << "--------------------------\n";
}

void timer(int i) {
    for ( ;i >= -1 ; i--) {
        displayClock();
        Sleep(900);
        seconds = i % 60;
        minutes = i % 3600 / 60;
        hours = i  / 3600 % 24;
    }
}

int main() {
    int n;
    cout << "Запустите таймер: ";
    cin >> n;
    timer(n);
    return 0;
}
