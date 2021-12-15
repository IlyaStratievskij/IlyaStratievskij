#include <iostream>
#include <ios>
#include <stdio.h>
#define SIZEARR 50

using namespace std;

int n = 8, m = 8, k = 14;
int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    //cin >> n >> m;
    //cin >> k;
    
    a = 0; b = 0; c = 0; d = 0;
    int myKoord[SIZEARR][SIZEARR] = { {2, 1}, {3, 1}, {3, 3}, {6, 3}, {6, 2}, {8, 2}, {8, 7}, {6, 7}, {6, 5}, {4, 5}, {4, 8}, {1, 8}, {1, 3}, {2, 3} };
    //int myKoord[SIZEARR][SIZEARR] = { {2, 5}, {2, 1}, {3, 1}, {3, 2}, {5, 2}, {5, 3}, {8, 3}, {8, 4}, {9, 4}, {9, 5}, {8, 5}, {8, 6}, {6, 6}, {6, 5} };
    double start = clock();

    int arr[SIZEARR][SIZEARR];
    int i, j, x, y;
    i = 0;
    while (i < m) {
        j = 0;
        while (j < n) {
            arr[i][j] = 0;
            j = j + 1;
        }
        i = i + 1;
    }
    int x1, y1, FirstX, FirstY;
    x = 0;
    y = 0;
    FirstX = 0; 
    FirstY = 0;
    i = 0;
    while (i < k) {
        x1 = x;
        y1 = y;
        x = myKoord[i][0];
        y = myKoord[i][1];
        //cin >> x >> y;
        if (!FirstX && !FirstY) {
            FirstX = x;
            FirstY = y;
        }

        if (x1 && y1) {
            if (x > x1) {
                while (x1 != x) {
                    x1 = x1 + 1;
                    arr[m - y1][x1 - 1] = 2;
                    if (arr[m - y1 - 1][x1 - 1] == 0) arr[m - y1 - 1][x1 - 1] = 1;
                }
            }
            else if (x < x1) {
                while (x1 != x) {
                    x1 = x1 - 1;
                    arr[m - y1][x1 - 1] = 2;
                    if (arr[m - y1 + 1][x1 - 1] == 0) arr[m - y1 + 1][x1 - 1] = 1;
                }
            }
            else if (y > y1) {
                while (y1 != y) {
                    y1 = y1 + 1;
                    arr[m - y1][x1 - 1] = 2;
                    if (arr[m - y1][x1 - 2] == 0) arr[m - y1][x1 - 2] = 1;
                }
            }
            else if (y < y1) {
                while (y1 != y) {
                    y1 = y1 - 1;
                    arr[m - y1][x1 - 1] = 2;
                    if (arr[m - y1][x1] == 0) arr[m - y1][x1] = 1;
                }
            }
        }
        arr[m - y][x - 1] = 5;

        i = i + 1;
    }
    if (x > FirstX) {
        while (x != FirstX+1) {
            x = x - 1;
            arr[m - y][x - 1] = 2;
            if (arr[m - y + 1][x - 1] == 0) arr[m - y + 1][x - 1] = 1;
        }
    }
    else if (x < FirstX) {
        while (x != FirstX-1) {
            x = x + 1;
            arr[m - y][x - 1] = 2;
            if (arr[m - y - 1][x - 1] == 0) arr[m - y - 1][x - 1] = 1;
        }
        
    }
    else if (y > FirstY) {
        while (y != FirstY+1) {
            y = y - 1;
            arr[m - y][x - 1] = 2;
            if (arr[m - y][x] == 0) arr[m - y][x] = 1;
        }
    }
    else if (y < FirstY) {
        while (y != FirstY-1) {
            y = y + 1;
            arr[m - y][x - 1] = 2;
            if (arr[m - y][x - 2] == 0) arr[m - y][x - 2] = 1;
        }
    }
    
    i = 0;
    while (i < m) {
        j = 0;
        while (j < n) {
            if (arr[i][j] == 0 && i != 0 && i != m - 1 && j != 0 && j != n - 1) {
                if (arr[i][j + 1] == 1 || arr[i][j - 1] == 1 || arr[i + 1][j] == 1 || arr[i - 1][j] == 1) arr[i][j] = 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < m) {
        j = 0;
        while (j < n) {
            if (arr[i][j] == 5 ) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    arr[i][j] = 3;
                    c = c + 1;
                }
                else if (arr[i][j + 1] == 0 || arr[i][j - 1] == 0 || arr[i + 1][j] == 0 || arr[i - 1][j] == 0) {
                    arr[i][j] = 3;
                    c = c + 1;
                }
                else {
                    arr[i][j] = 4;
                    d = d + 1;
                }

            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < m) {
        j = 0;
        while (j < n) {
            //arr[i][j] == 1 ? a = a + 1 : arr[i][j] == 2 ? b = b + 1 : 0;
            if (arr[i][j] == 1) a = a + 1;
            if (arr[i][j] == 2) b = b + 1;
            j = j + 1;
        }
        i = i + 1;
    }
    printf("%d %d %d %d\n", a, b, c, d);
    printf("\nTime code = %lf\n", clock() - start);

    printf("picture:\n");
    i = 0;
    while (i < m) {
        j = 0;
        while (j < n) {
            printf("%d", arr[i][j]);
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }
}