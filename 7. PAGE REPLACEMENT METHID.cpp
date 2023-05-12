#include <stdio.h>

int main() {
    int page_frames = 3;
    int page_sequence[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_pages = sizeof(page_sequence) / sizeof(int);
    int page_faults = 0;
    int page_table[page_frames];
    int last_use[page_frames];
    int i, j, k;
    for (i = 0; i < page_frames; i++) {
        page_table[i] = -1;
        last_use[i] = -1;
    }
    for (i = 0; i < num_pages; i++) {
        int page = page_sequence[i];
        int page_index = -1;
        for (j = 0; j < page_frames; j++) {
            if (page_table[j] == page) {
                page_index = j;
                break;
            }
        }
        if (page_index == -1) {
            page_faults++;
            int oldest_page_index = 0;
            for (j = 1; j < page_frames; j++) {
                if (last_use[j] < last_use[oldest_page_index]) {
                    oldest_page_index = j;
                }
            }
            page_index = oldest_page_index;
            page_table[page_index] = page;
        }
        last_use[page_index] = i;
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
