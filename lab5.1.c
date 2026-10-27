#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n, m, i = 0, j = 0, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter elements of first array: ");
    for (int x = 0; x < n; x++)
        scanf("%d", &a[x]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter elements of second array: ");
    for (int x = 0; x < m; x++)
        scanf("%d", &b[x]);

    while (i < n && j < m) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < n)
        c[k++] = a[i++];

    while (j < m)
        c[k++] = b[j++];

    printf("Merged array: ");
    for (int x = 0; x < k; x++)
        printf("%d ", c[x]);

    return 0;
}