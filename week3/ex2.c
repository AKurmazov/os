#include <stdio.h>
const int N = 5;

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubble_sort(int array[N]) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int main() {
    int array[N] = {1, 2, 5, 4, 3};

    bubble_sort(array);
    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}