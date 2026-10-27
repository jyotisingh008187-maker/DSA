#include <stdio.h>

int a[100], temp[100];

long long merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    long long inv = 0;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l; i <= r; i++)
        a[i] = temp[i];

    return inv;
}

long long mergeSort(int l, int r) {
    long long inv = 0;

    if (l < r) {
        int mid = l + (r - l) / 2;

        inv += mergeSort(l, mid);
        inv += mergeSort(mid + 1, r);
        inv += merge(l, mid, r);
    }

    return inv;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Inversions = %lld\n",
           mergeSort(0, n - 1));

    return 0;
}