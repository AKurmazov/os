#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    int hits = 0;
    int misses = 0;
    int size = 1000; // Change if necessary

    FILE *input_file;
    input_file = fopen("input_data.txt", "r");

    int *frames = (int *) malloc(size * sizeof(int));
    int *hm = (int *) malloc(size * sizeof(int));

    memset(frames, 0, size);
    memset(hm, 0, size);

    int page_num;
    int count = 0;
    while (fscanf(input_file, "%d", &page_num) != EOF) {
        count++;
        if (count > size) {
            break;
        }

        int is_hit = 0;
        for (int i = 0; i < size; ++i) {
            if (page_num == frames[i]) {
                hm[i] = (hm[i] >> 1) | (1 << 7);
                hits++;

                is_hit = 1;
                break;
            }
        }

        if (!is_hit) {
            int min_i = 0;

            for (int i = 0; i < size; ++i) {
                if (hm[i] < hm[min_i]) {
                    min_i = i;
                }
            }

            frames[min_i] = page_num;
            hm[min_i] = 0 | (1 << 7);
            misses++;
        }
    }

    fclose(input_file);
    printf("Hits: %d\nMisses: %d\n", hits, misses);
    printf("Hit/Miss ratio: %lf\n", (double) hits / (double) misses);

    return 0;
}