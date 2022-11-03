// БИНАРНЫЙ ПОИСК
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int BinarySearch(vector<int> arr, int k) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == k)
            return m + 1;
       else if (arr[m] > k)
            r = m - 1;
        else
           l = m + 1;
    }
    return -1;
}
int main(void) {
    int n, tr;
    cin >> n; // количество чисел
    vector <int> arr(n);
    for (auto& numb : arr)
        cin >> numb; // числа, в которых будет производиться поиск

    sort(arr.begin(), arr.end());
    int temp;
    cin >> temp; // количесвто искомых чисел
    int num[99999];
    for (int i = 0; i < temp; i++) {
        cin >> num[i]; // искомые числа
    }
    for (int i = 0; i < temp; i++)
        cout << BinarySearch(arr, num[i]) << " ";
}