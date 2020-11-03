#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char** argv) {

    char* mode;
    char c;

    if (argc == 1) {
        while(fread(&c, 1, 1, stdin)) {
            printf("%c", c);
        }

        return 0;
    }

    int outs_num, offset;
    if (strcmp(argv[1], "-a") == 0) {
        mode = "a+";
        offset = 2;
    } else {
        mode = "w+";
        offset = 1;
    }
    outs_num = argc - offset;

    FILE **outs = malloc((outs_num + 1) * sizeof(FILE*));
    for (int i = offset; i < argc; ++i) {
        outs[i - offset] = fopen(argv[i], mode);
    }
    outs[outs_num] = stdout;

    while(fread(&c, 1, 1, stdin)) {
        for (int i = 0; i <= outs_num; ++i) {
            fwrite(&c, 1, 1, outs[i]);
        }
    }

    for (int i = 0; i < outs_num; ++i) {
        fclose(outs[i]);
    }

    return 0;
}