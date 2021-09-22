#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

int hours = 0;
int minutes = 0;
int seconds = 0;
void displayClock() {
    system("cls");
    cout << setfill(' ') << setw(55) << "           TIMER          \n";
    cout << setfill(' ') << setw(55) << "--------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec | " << endl;
    cout << setfill(' ') << setw(55) << "--------------------------\n";
}

void timer() {
    while(true) {
        displayClock();
        Sleep(2);
        seconds++;
        if (seconds == 60) {
            minutes++;
            if (minutes == 60) {
                hours++;
                minutes = 0;
            }
            seconds = 0;
        }
    }
}

int main() {
    timer();
    return 0;
}
