#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int SecretNumber = rand() % 100 + 1;
    int tries = 0;
    int guess;
    cout << "\nWelcome to Guess My Number\n\n";
    
    do {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;
        if (guess > SecretNumber) cout << "Too high!\n\n";
        else if (guess < SecretNumber) cout << "Too low!\n\n";
        else cout << "\nThat's it! You got it in " << tries << " guesses!\n";
    } while (guess != SecretNumber);
    
    return 0;
}