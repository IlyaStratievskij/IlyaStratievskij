#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(0));
    int h, w;
    scanf("%d%d", &h, &w);
    int s = h * w;
    int a[h][w];
    int i, j, k, l = 0, r = -1;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            a[i][j] = rand() % 15;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    i = 0, j = 0;
    if (h != 0 && w != 0)
    while (1) {
        while (j != w) {
            printf("%d ", a[i][j]);
            j++;
            s--;
        }
        j--;
        i++;
        w--;
        if (!s) break;
        //printf("\n%d %d\n", i, j);
        
        while (i != h) {
            printf("%d ", a[i][j]);
            i++;
            s--;
        }
        i--;
        j--;
        h--;
        if (!s) break;
        //printf("\n%d %d\n", i, j);
        
        while (j != r) {
            printf("%d ", a[i][j]);
            j--;
            s--;
        }
        i--;
        j++;
        r++;
        if (!s) break;
        //printf("\n%d %d\n", i, j);
        
        while (i != l) {
            printf("%d ", a[i][j]);
            i--;
            s--;
        }
        i++;
        j++;
        l++;
        if (!s) break;
        //printf("\n%d %d\n", i, j);
        
    }
    return 0;
}
