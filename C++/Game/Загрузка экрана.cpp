#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

char animationChar[] = {'|', '/', '-', '\\'};


int main() {
    system ("cls");

    for (int i = 0; i <= 100; i++) {
            Sleep (250);
        cout << "Processing: " << i << "% " << animationChar[i % 4] << "\r";
    }
    cout << "Processing: Done!";
}