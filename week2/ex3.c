#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int indent = n - i - 1;
        int width = i * 2 + 1;

        printf("%*s", indent, "");
        for (int j = 0; j < width; ++j) {
            printf("%s", "*");
        }
        printf("\n");
    }

    return 0;
}