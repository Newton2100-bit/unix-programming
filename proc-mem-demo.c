// test_memory.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("PID: %d\n", getpid());
    printf("Check /proc/%d/maps now!\n", getpid());
    sleep(5);
    
    // Allocate heap memory
    printf("Allocating 10MB on heap...\n");
    char *heap = malloc(10 * 1024 * 1024);
    for (int i = 0; i < 10 * 1024 * 1024; i++) {
        heap[i] = 'A';  // Touch pages to actually allocate
    }
    printf("Check maps again - heap grew!\n");
    sleep(5);
    
    // Recursive function to grow stack
    void grow_stack(int depth) {
        char stack_array[10000];  // 10KB on stack
        stack_array[0] = 'B';     // Touch it
        printf("Stack depth: %d\n", depth);
        if (depth < 100) {
            grow_stack(depth + 1);
        }
        sleep(1);
    }
    
    printf("Growing stack...\n");
    grow_stack(0);
    
    printf("Check maps one more time!\n");
    sleep(10);
    
    free(heap);
    return 0;
}
