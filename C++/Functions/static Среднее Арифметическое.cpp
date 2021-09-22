#include <iostream>
using namespace std;

double running(int i) {
    static double sum = 0, count = 0;
    
    sum += i;
    count++;
    
    return sum/count;
}

int main() {
    int num;
    do {
        cout << "Enter number (-1 this is exit): ";
        cin >> num;
        if (num != -1) cout << "current average is: " << running(num);
        cout << endl;
    } while (num > -1);
    return 0;
}