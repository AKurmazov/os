#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int a, b, temp;
    scanf("%d %d", &a, &b);

    swap(&a, &b);

    printf("%d %d\n", a, b);

    return 0;
}