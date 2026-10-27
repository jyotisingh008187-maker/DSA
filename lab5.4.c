#include <stdio.h>

int a[100], temp[100];

void merge(int a[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l; i <= r; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int n, i, count;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    i = 0;
    while (i < n) {
        count = 1;

        while (i + count < n &&
               a[i + count] == a[i]) {
            count++;
        }

        if (count > n / 2) {
            printf("Majority = %d\n", a[i]);
            return 0;
        }

        i += count;
    }

    printf("No majority\n");

    return 0;
}