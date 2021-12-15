#include <iostream>
#include <algorithm>
#include <memory.h>
#define SIZEARR 3

using namespace std;


int main()
{
    int arr[SIZEARR], newArr[SIZEARR];
    for (int i = 0; i < SIZEARR; i++)
        cin >> arr[i];
    memcpy(newArr, arr, sizeof(arr));
    
    for (int k = 0; k < SIZEARR; k++) {
        bool findMedian = false;

        memcpy(arr, newArr, sizeof(newArr));
        int m = arr[k];
        sort(arr, arr + SIZEARR);
        
        if (arr[1] == m) {
            cout << "YES\n";
            continue;
        }
        for (int i = 0; i < SIZEARR; i++) {
            findMedian = false;
            for (int j = 0; j < SIZEARR; j++) {
                m = newArr[k];
                memcpy(arr, newArr, sizeof(newArr));
                if (i != j) {
                    if (arr[i] == m) m -= arr[j];
                    arr[i] -= arr[j];
                    sort (arr, arr + SIZEARR);
                    if (arr[1] == m) {
                        cout << "YES\n";
                        findMedian = true;
                        break;
                    }
                }
            }
            if (findMedian) break;
        }
        if (!findMedian) cout << "NO\n";
        
    }
    
    return 0;
}