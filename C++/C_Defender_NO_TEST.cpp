#include <iostream>
#define SIZEARR 99

using namespace std;

int myMin(int arr[], int n) {
    int min = -1, minId;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            min = arr[i];
            minId = i;
            break;
        }
    }
    if (min == -1) return -1;
    for (int i = minId; i < n; i++)
        if (arr[i] <= min && arr[i] >= 0) {
            min = arr[i];
            minId = i;
        }

    return minId;
 
}

int main()
{
    int n, m, sum = 0;
    cin >> n >> m;

    int lenPlit[SIZEARR], numbDefiner[SIZEARR];

    for (int i = 0; i < n; i++)
        cin >> lenPlit[i];
    for (int i = 0; i < m; i++)
        cin >> numbDefiner[i];
    
    lenPlit[n] = 0;
    for (int i = n; i > 0; i--) {
        int r = lenPlit[i-1] - lenPlit[i];
        if (r > 0) {
            int newArr[SIZEARR];
            for (int j = 0; j < m; j++) {
                newArr[j] = r - numbDefiner[j];
            }
            int min = myMin(newArr, m);
            if (min >= 0 && newArr[min] >= 0 && newArr[min] <= r) {
                numbDefiner[min] = -1;
                sum++;
            }
        }
        else if (r < 0) lenPlit[i - 1] = lenPlit[i];
    }
    cout << sum;

    return 0;
}