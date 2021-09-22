#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, t, size;
    cin >> size;
    int nums[size];
    srand(time(0));

    for (t = 0;t < size; t++) nums[t] = (rand() % (size * 10)) ;

    //Отображаем исходный массив.
    cout <<  "Исходный массив:\n  ";
    for (t = 0; t < size; t++) cout << nums[t] << " ";
    cout << "\n";

    //Сортировка
    for (a = 1; a < size; a ++) {
        for (b = size - 1; b >= a; b--) {
            if (nums[b - 1] > nums[b]) {
                t = nums[b - 1];
                nums[b - 1] = nums[b];
                nums[b] = t;
            }
        }
    }

    //Отображаем отсортированный массив
    cout << "\nОтсортированный массив:\n   ";
    for (t = 0; t < size; t++) cout << nums[t] << " ";

    return 0;
}
