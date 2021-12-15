/*
// E_VERSION_Yandex_Test_with_while
#include <iostream>
#include <ios>
#include <ctime>
#include <stdio.h>
#include <iomanip>
#define SIZEARR 99

using namespace std;

int main()
{
    double start = clock();
    std::ios_base::sync_with_stdio(false);
    //std::cin.tie(0);

    int a = 6, b = 7, c = 8, sum = 0;
    //cin >> a >> b >> c;
    int q = 3;
    //cin >> q;
    int arr[4][SIZEARR] = { {3, 5, 2, 3}, {2, 2, 3, 6}, {1, 4, 3, 3} };
    //for (int i = 0; i < q; i++)
        //for (int j = 0; j < 4; j++)
            //cin >> arr[i][j];
    int i, j, k, l;
    int rule;
    i = 0;
    while (i < a) {
        j = 0;
        while (j < b) {
            k = 0;
            while (k < c) {
                rule = 1;
                l = 0;
                while (l < q) {
                    int numbOne, numbTwo;
                    numbOne = arr[l][0] == 1 ? i + 1 : arr[l][0] == 2 ? j + 1 : k + 1;
                    //if (arr[l][0] == 1) numbOne = i + 1;
                    //else if (arr[l][0] == 2) numbOne = j + 1;
                    //else if (arr[l][0] == 3) numbOne = k + 1;

                    numbTwo = arr[l][2] == 1 ? i + 1 : arr[l][2] == 2 ? j + 1 : k + 1;
                    //if (arr[l][2] == 1) numbTwo = i + 1;
                    //else if (arr[l][2] == 2) numbTwo = j + 1;
                    //else if (arr[l][2] == 3) numbTwo = k + 1;

                    if (numbOne >= arr[l][1] && numbTwo < arr[l][3]) {
                        rule = 0;
                        break;
                    }
                    l = l + 1;
                }
                if (rule)
                    sum++;

                k = k + 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    
    printf("%d\n", sum);
    double end = clock();
    //cout << setprecision(5) << fixed;
    printf("%lf", end - start);
    return 0;
}
*/

// E_VERSION_Yandex_Test_with_for
#include <iostream>
#include <ios>
#define SIZEARR 99

using namespace std;

int main()
{
    double start = clock();

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int a = 6, b = 7, c = 8, sum = 0;
    //cin >> a >> b >> c;
    int q = 3;
    //cin >> q;
    int arr[4][SIZEARR] = { {3, 5, 2, 3}, {2, 2, 3, 6}, {1, 4, 3, 3} };
    //for (int i = 0; i < q; i++)
        //for (int j = 0; j < 4; j++)
            //cin >> arr[i][j];

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            for (int k = 0; k < c; k++) {
                bool rule = true;
                for (int l = 0; l < q; l++) {
                    int numbOne, numbTwo;
                    numbOne = arr[l][0] == 1 ? i + 1 : arr[l][0] == 2 ? j + 1 : k + 1;
                    //if (arr[l][0] == 1) numbOne = i + 1;
                    //else if (arr[l][0] == 2) numbOne = j + 1;
                    //else if (arr[l][0] == 3) numbOne = k + 1;

                    numbTwo = arr[l][2] == 1 ? i + 1 : arr[l][2] == 2 ? j + 1 : k + 1;
                    //if (arr[l][2] == 1) numbTwo = i + 1;
                    //else if (arr[l][2] == 2) numbTwo = j + 1;
                    //else if (arr[l][2] == 3) numbTwo = k + 1;

                    if (numbOne >= arr[l][1] && numbTwo < arr[l][3]) {
                        rule = false;
                        break;
                    }

                }
                if (rule)
                    sum++;
            }

    printf("%d", sum);
    printf("\n%lf", clock() - start);
    return 0;
}
