/* Convert an array into a heap
 * Output number of swaps, followed by m lines of the swaps
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEFT(i)             ((2 * i) + 1)
#define RIGHT(i)            ((2 * i) + 2)

int heapify(int *list, int end, int print_swap);                                /* Turn an unsorted list into a heap */
int do_heapify(int *list, int i, int end, int print_swap);                      /* Turn an unsorted list into a heap (for functional style) */
void sift_down(int *heap, int i, int end, int *swaps, int print_swap);          /* Sift value in heap down from index i until at most index end */
void swap(int *i, int *j);                                                   /* Swap the values of two integer pointers */
int read_word(char *buffer);                                                 /* Read until white space from stdin */

int main(void) {
    char buffer[7];             /* Store ascii of n, which has a max value of 100,000 */
    char *p_buffer = buffer;    /* Pointer to buffer */
    int n;                      /* The integer value of n_ascii */

    read_word(buffer);          /* Read first line of stdin into the buffer */
    n = atoi(buffer);           /* Convert ascii in buffer to integer value of n */
    p_buffer = buffer;          /* Reset p_buffer before it is used again */

    int heap1[n], *p_heap1 = heap1;    /* Initialize heap1 */
    int heap2[n], *p_heap2 = heap2;    /* Initialize heap2 */

    while (read_word(buffer) != EOF) {  /* Read values in given order into heap */
        *(p_heap1++) = atoi(buffer);
        *(p_heap2++) = atoi(buffer);
    }

    int swaps = heapify(heap1, n, 0);       /* Heapify the list */
    printf("%d\n", swaps);              /* Report number of swaps */

    heapify(heap2, n, 1);

    return 0;
}

int read_word(char *buffer) {
    while(!isspace(*buffer = getchar()) && *buffer != EOF) {
        ++buffer;
    }
    char c = *buffer;
    *buffer = '\0';
    return c;
}

/* Turn a list into a heap */
int heapify(int *list, int length, int print_swap) {
    return do_heapify(list, (length / 2) - 1, length - 1, print_swap);
}

/* Turn a list into a heap */
int do_heapify(int *list, int n, int end, int print_swap) {
    static int swaps = 0;

    /* base case */
    if (n < 0) {
        return swaps;
    }

    /* recursive case */
    sift_down(list, n, end, &swaps, print_swap);
    return do_heapify(list, n - 1, end, print_swap);
}

/* Sift element in heap down from position 'i' until at most 'end' */
void sift_down(int *heap, int i, int end, int *swaps, int print_swap) {

    /* if left and right are within the heap ... */
    if (LEFT(i) <= end && RIGHT(i) <= end) {
        int min = (heap[LEFT(i)] < heap[RIGHT(i)]) ? LEFT(i) : RIGHT(i);

        /* ... if heap at i is greater than heap at min */
        if (heap[i] > heap[min]) {
            if (print_swap) {
                printf("%d %d\n", i, min);
            }
            swap(heap + i, heap + min);
            *swaps += 1;

            /* recursive case */
            return sift_down(heap, min, end, swaps, print_swap);
        }
    
    /* if left is within the heap, and heap at i is greater than than heap at left */
    } else if (LEFT(i) <= end && heap[i] > heap[LEFT(i)]) {
        if (print_swap) {
            printf("%d %d\n", i, LEFT(i));
        }
        swap(heap + i, heap + LEFT(i));
        *swaps += 1;
    }

    /* base case */
    return;
}

/* Swap values of two integer pointers */
void swap(int *i, int *j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
    return;
}
