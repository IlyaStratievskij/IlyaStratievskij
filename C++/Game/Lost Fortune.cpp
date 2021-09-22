#include <iostream>
#include <string>
using namespace std;

int main() {
    const int GOLD_PIECES = 900;
    int advanturers, killed, survivors;
    string leader;
    //получаем информацию
    cout << "Welcome to Lost Fortune\n\n";
    cout << "Please enter the following for your personalized adventure\n";
    cout << "Enter a number: ";
    cin >> advanturers;
    cout << "Enter a number, smaller then the first: ";
    cin >> killed;
    survivors = advanturers - killed;
    cout << "Enter your last name: ";
    cin >> leader;
    
    //сюжет
    cout << "\nA brave group of " << advanturers << " set out on a quest ";
    cout << "-- in search of the lost treasure of the Ancient Dwarves. ";
    cout << "The group was led by that legendary rogue, " << leader << endl;
    cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
    cout << "All fought bravely under the command of " << leader;
    cout << ", and the orges were defeated, but at a cost. ";
    cout << "Of the adventurers. " << killed << " were vanquished. ";
    cout << "leaving just " << survivors << " in the group.\n";
    cout << "\nThe party was about to give up all hope. ";
    cout << "But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
    cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course.\n";
    
    return 0;
}