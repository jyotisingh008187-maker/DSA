#include <stdio.h>

int main() {
    int n, key, i;
    int floor = 0, found = 0;

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
            floor = a[mid];
            found = 1;
            break;
        } 
        else if (a[mid] < key) {
            floor = a[mid];
            found = 1;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    if (found)
        printf("Floor = %d", floor);
    else
        printf("none");

    return 0;
}