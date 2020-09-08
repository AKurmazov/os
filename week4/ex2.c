#include <stdio.h>
#include <unistd.h>

/*
 * If the loop has 3 iterations, then 8 processes are created
 * If the loop has 5 iterations, then 32 processes are created
 *
 * Since fork creates a duplicate of a current process, the
 * overall number of processes doubles every iteration, therefore,
 * if the loop is run:
 *  1) 3 times -> 2^3 = 8 processes
 *  2) 5 times -> 2^5 = 32 processes
 *
 * The same numbers we've obtained running this code
*/

int main() {
    for (int i = 0; i < 5; ++i) {
        fork();
        sleep(5);
    }
    return 0;
}