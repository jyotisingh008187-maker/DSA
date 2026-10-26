#include <stdio.h>

int main() {
    int n, key, i;
    int index = -1;

    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &key);

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == key) {
            index = mid;
            break;
        }

        // Left half is sorted
        if (a[low] <= a[mid]) {
            if (key >= a[low] && key < a[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {
            if (key > a[mid] && key <= a[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    if (index != -1)
        printf("Found at index %d", index);
    else
        printf("Not found");

    return 0;
}