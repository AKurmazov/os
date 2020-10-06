#include <stdlib.h>
#include <zconf.h>
#include <string.h>

int main() {
    int size = 10 * 1024 * 1024; // 10 MB

    for (int i = 0; i < 10; ++i) {
        int *allocated = (int *) malloc(size);
        memset(allocated, 0, size);

        sleep(1);
    }

    return 0;
}