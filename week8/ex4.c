#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    int size = 10 * 1024 * 1024; // 10 MB
    int who = RUSAGE_SELF;
    struct rusage usage;

    for (int i = 0; i < 10; ++i) {
        int *allocated = (int *) malloc(size);
        memset(allocated, 0, size);

        int ret = getrusage(who, &usage);
        printf("Memory usage: %ld\n", usage.ru_maxrss);

        sleep(1);
    }

    return 0;
}