#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Size of a: %lu bytes\nSize of b: %lu bytes\nSize of c: %lu bytes\n", sizeof(a), sizeof(b), sizeof(c));
    printf("Value of a: %d\nValue of b: %e\nValue of c: %e\n", a, b, c);

    return 0;
}