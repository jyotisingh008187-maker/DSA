#include <stdio.h>

int main() {
    int m, n, key, i, j;
    int found = 0;

    scanf("%d %d", &m, &n);

    int a[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d", &key);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == key) {
                printf("Found at (%d, %d)", i, j);
                found = 1;
                break;
            }
        }

        if (found)
            break;
    }

    if (!found)
        printf("Not found");

    return 0;
}