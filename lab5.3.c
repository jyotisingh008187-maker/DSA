#include <stdio.h>

int a[100], subset[100];
int n, count = 0;

void powerSet(int index, int size) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < size; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        count++;
        return;
    }

    // Exclude the current element
    powerSet(index + 1, size);

    // Include the current element
    subset[size] = a[index];
    powerSet(index + 1, size + 1);
}

int main() {
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    powerSet(0, 0);

    printf("Count = %d\n", count);

    return 0;
}