#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() 
{
    string numb;
    int currBase, newBase;
    cin >> numb;
    cin >> currBase >> newBase;
    
    int number = 0;
    
    int s = numb.length() - 1;
    for (int i = 0; i < numb.length(); i++) 
    {
        if (numb[i] == 'A') number += 10 * pow(currBase, s);
        else if (numb[i] == 'B') number += 11 * pow(currBase, s);
        else if (numb[i] == 'C') number += 12 * pow(currBase, s);
        else if (numb[i] == 'D') number += 13 * pow(currBase, s);
        else if (numb[i] == 'E') number += 14 * pow(currBase, s);
        else if (numb[i] == 'F') number += 15 * pow(currBase, s);
        else number += (numb[i] & 0x0F) * pow(currBase, s);
        s--;
    }
    
    cout << "Number with base 10 = " << number << endl;
    
    char arr[10];
    int len = 0;
    for (int i = 0; number != 0; i++)
    {
        int temp = 0;
        temp = number % newBase;
        if (temp == 10) strcat(arr, "A");
        else if (temp == 11) strcat(arr, "B");
        else if (temp == 12) strcat(arr, "C");
        else if (temp == 13) strcat(arr, "D");
        else if (temp == 14) strcat(arr, "E");
        else if (temp == 15) strcat(arr, "F");
        else arr[i] = temp | 0x30;
        
        number /= newBase;
        len++;
    }
    
    cout << "Number with base " << newBase << " = ";
    for (int i = len - 1; i >= 0; i--) 
        cout << arr[i];
    
}
