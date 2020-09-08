#include <stdio.h>
#include <unistd.h>

/*
 * The output is in the form of:
 * Hello from parent [PID - X]
 * Hello from child [PID - X]
 * Hello from child [PID - Y]
 *
 * It is shown by this diagram:
 *    X
 *  /   \ fork
 * X     Y
 *
 * When the code is run 10 times, the output will be formed as before,
 * but repeated 10 times. The PID of a new parent is almost always
 * bigger than the PID of the just finished child (usually by 1)
*/

int main() {
    int n = getpid();
    printf("Hello from parent [PID - %d]\n", n);
    fork();
    n = getpid();
    printf("Hello from child [PID - %d]\n", n);
    return 0;
}