#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 40

int main() {
    char cmd[MAX_INPUT_LENGTH];

    printf("Your command: ");
    scanf("%s", cmd);

    system(cmd);
    return 0;
}