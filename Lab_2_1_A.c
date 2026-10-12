#include <stdio.h>

void badSwap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    badSwap(a, b);

    printf("badSwap: %d %d", a, b);

    return 0;
}