#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 80

int main() {

    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];

    printf("Your command: ");
    scanf("%[^\n]", input);

    int count = 1;
    if (input > 0) {
        for (int i = 0; input[i] != '\0'; ++i) {
            if (input[i] == ' ' || input[i] == '\n') {
                count++;
            }
        }
    }

    // Tokenize the initial input into separable arguments
    args[0] = strtok(input, " ");
    for (int i = 1; i < count; ++i) {
        args[i] = strtok(NULL, " ");
    }

    // Check if a & is added
    if (!strcmp(args[count-1], "&")) {
        args[count - 1] = NULL;
    } else {
        args[count] = NULL;
        count++;
    }

    int status = fork();
    if (status == -1) {
        return 1;
    } else if (status == 0) {
        execvp(args[0], args);
    } else {
        int response;
        wait(&response);
    }
    return 0;
}