#include <stdio.h>

int main() {
    int n, key, i;
    int linear = 0, binary = 0, index = -1;

    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &key);

    // Linear search
    for (i = 0; i < n; i++) {
        linear++;

        if (a[i] == key) {
            break;
        }
    }

    // Binary search
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        binary++;

        if (a[mid] == key) {
            index = mid;
            break;
        } 
        else if (a[mid] < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    printf("Linear = %d, Binary = %d", linear, binary);

    return 0;
}