#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir1 = opendir("tmp");
    if (dir1 == NULL) {
        return 1;
    }

    struct dirent *dp1;
    while ((dp1 = readdir(dir1)) != NULL) {
        DIR *dir2 = opendir("tmp");
        struct dirent *dp2;
        printf("Link: %s\n", dp1->d_name);
        printf("Linked files: ");
        while ((dp2 = readdir(dir2)) != NULL) {
            if (strcmp(dp1->d_name, dp2->d_name) && (dp1->d_ino == dp2->d_ino)) {
                printf("%s ", dp2->d_name);
            }
        }
        printf("\n");
        (void) closedir(dir2);
    }

    (void) closedir(dir1);
    return 0;
}