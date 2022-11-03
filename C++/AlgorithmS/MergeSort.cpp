// СОРТИРОВКА СЛИЯНИЕМ
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;
int sum;
vector <int> Merge(vector <int> a, vector <int> b) {
    vector <int> res;
    int ita = 0, itb = 0;
    int lena = a.size(), lenb = b.size();
    while (res.size() != lena + lenb) {
        if (ita < lena && itb < lenb) {
            if (a[ita] > b[itb]) {
                sum += (a.size() - ita);
                res.push_back(b[itb]);
                itb++;
            }
            else {
                res.push_back(a[ita]);
                ita++;
            }
        }
        else {
            if (ita < lena) {
                res.push_back(a[ita]);
                ita++;
            }
            else {
                res.push_back(b[itb]);
                itb++;
            }
        }
    }
    return res;
}

vector <int> MergeSort(vector <int> arr, int l , int r) {
    if (l < r) {
        int m = (l + r) / 2;
        return Merge(MergeSort(arr, l, m), MergeSort(arr, m + 1, r));
    }
    else {
        vector <int> res;
        res.push_back(arr[l]);
        return res;
    }
}

int main()
{
    srand(time(NULL));
    vector <int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 100);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n---------------------------------------------------------------" << endl;
    vector <int> res;
    res = MergeSort(arr, 0, arr.size() - 1);
    int lenres = res.size();
    for (int i = 0; i < lenres; i++)
        cout << res[i] << " ";
    //cout << endl << sum; // для задачки в Stepik;
    return 0;
}