#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define N 20

int main() {

    int random_file = open("/dev/random", O_RDONLY);
    int out_file = open("ex1.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    if (random_file < 0) {
        printf("An error occured when opening the file");
    } else {
        char *random_data = (char *) malloc(N * sizeof(char));
        ssize_t size = read(random_file, random_data, sizeof(random_data));
        if (size < 0) {
            printf("An error occured when reading the file");
        } else {
            write(out_file, random_data, size);
        }
        free(random_data);
    }

    close(random_file);
    close(out_file);

    return 0;
}