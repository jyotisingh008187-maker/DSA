#include <stdio.h>

int main() {
    int a[100], n, i, j, maxIndex, temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++) {
        maxIndex = i;

        for (j = i + 1; j < n; j++) {
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }

        temp = a[i];
        a[i] = a[maxIndex];
        a[maxIndex] = temp;
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}