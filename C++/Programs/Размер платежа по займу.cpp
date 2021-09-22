#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Principal;
    double IntRate;
    double PayPerYear;
    double NumYear;
    double Payment;
    double numer, denom;
    double b, e;
    cout << "Введите исходную сумму займа: ";
    cin >> Principal;
    cout << "Введите процентную ставку (например, 0.075): ";
    cin >> IntRate;
    cout << "Введите количество выплат в год: ";
    cin >> PayPerYear;
    cout << "Введите срок займа(в годах): ";
    cin >> NumYear;
    numer = IntRate * Principal / PayPerYear;
    e = -(PayPerYear * NumYear);
    b = (IntRate / PayPerYear) + 1;
    denom = 1 - pow(b, e);
    Payment = numer / denom;
    cout << "Размер платежа по займу составляет " << Payment;
    return 0;
}
