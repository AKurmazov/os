#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main() {

    int fd_in = open("ex1.txt", O_RDONLY);
    int fd_out = open("ex1.memcpy.txt", O_RDWR | O_CREAT);

    int length = lseek(fd_in, 0, SEEK_END);
    ftruncate(fd_out, length);

    char *map_in = mmap(NULL, length, PROT_READ, MAP_SHARED, fd_in, 0);
    char *map_out = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd_out, 0);

    if (map_in < 0 || map_out < 0) {
        printf("Mapping error\n");
        return 3;
    }

    memcpy(map_out, map_in, length);
    munmap(map_in, length);
    munmap(map_out, length);

    close(fd_in);
    close(fd_out);

    return 0;
}