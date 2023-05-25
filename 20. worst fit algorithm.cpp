#include<stdio.h>
#include<stdlib.h>
#define MAX 10 
int memory[MAX]; 
int n; 
void worst_fit(int process_size) {
    int i, j, index = -1, max_frag = -1;
    for(i=0; i<n; i++) {
        if(memory[i] >= process_size) {
            if(memory[i] - process_size > max_frag) {
                max_frag = memory[i] - process_size;
                index = i;
            }
        }
    }
    if(index != -1) {
        memory[index] -= process_size;
        printf("Process of size %d KB is allocated to memory partition %d.\n", process_size, index+1);
    }
    else {
        printf("Process of size %d KB cannot be allocated.\n", process_size);
    }
}

int main() {
    int i, process_size;
    memory[0] = 300;
    memory[1] = 600;
    memory[2] = 350;
    memory[3] = 200;
    memory[4] = 750;
    memory[5] = 125;
    n = 6;

    printf("Memory partitions:\n");
    for(i=0; i<n; i++) {
        printf("%d. %d KB\n", i+1, memory[i]);
    }

    printf("\nAllocating processes:\n");
    process_size = 115;
    worst_fit(process_size);
    process_size = 500;
    worst_fit(process_size);
    process_size = 358;
    worst_fit(process_size);
    process_size = 200;
    worst_fit(process_size);
    process_size = 375;
    worst_fit(process_size);

    return 0;
}
