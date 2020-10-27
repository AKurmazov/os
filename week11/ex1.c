#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() {

    const char *text = "This is a nice day";
    size_t size = strlen(text);

    int fd = open("ex1.txt", O_RDWR);
    if (fd < 0) {
        printf("%s\n", "Open file error");
        return 1;
    }
    ftruncate(fd, size);

    struct stat st;
    int sterr = fstat(fd, &st);
    if (sterr < 0) {
        printf("%s\n", "Get file stats error");
        return 2;
    }

    char *map = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        printf("%s\n", "Mapping error");
        return 3;
    }

    for (size_t i = 0; i < st.st_size; ++i) {
        map[i] = text[i];
    }

    munmap(map, st.st_size);
    close(fd);

    return 0;
}