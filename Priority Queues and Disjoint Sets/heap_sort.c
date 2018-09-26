/* Heap sort */

#include <stdio.h>
#define LEFT(i)             ((2 * i) + 1)
#define RIGHT(i)            ((2 * i) + 2)

void heap_sort(int *, int);         /* Heap sort algorithm */
void do_heap_sort(int *, int);      /* Heap sort algorithm (for functional style) */
void heapify(int *, int);           /* Turn an unsorted list into a heap */
void do_heapify(int *, int, int);   /* Turn an unsorted list into a heap (for functional style) */
void sift_down(int *, int, int);    /* Sift value in heap down from index i until at most index end */
void swap(int *, int *);            /* Swap the values of two integer pointers */

int main(void) {
    int list[] = {2, 2, 3, -1};
    int len = 4;

    heap_sort(list, len);

    for (int i = 0; i < len; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}

/* Heap sort */
void heap_sort(int *list, int length) {
    heapify(list, length);
    return do_heap_sort(list, length - 1);
}

/* Heap sort */
void do_heap_sort(int *list, int end) {
    /* base case */
    if (end <= 0) {
        return;
    }

    /* recursive case */
    swap(list, list + end);
    sift_down(list, 0, end - 1);
    return do_heap_sort(list, end - 1);
}

/* Turn a list into a heap */
void heapify(int *list, int length) {
    do_heapify(list, (length / 2) - 1, length - 1);
    return;
}

/* Turn a list into a heap */
void do_heapify(int *list, int n, int end) {
    /* base case */
    if (n < 0) {
        return;
    }

    /* recursive case */
    sift_down(list, n, end);
    return do_heapify(list, n - 1, end);
}

/* Sift element in heap down from position 'i' until at most 'end' */
void sift_down(int *heap, int i, int end) {

    /* if left and right are within the heap ... */
    if (LEFT(i) <= end && RIGHT(i) <= end) {
        int max = (heap[LEFT(i)] > heap[RIGHT(i)]) ? LEFT(i) : RIGHT(i);

        /* ... if heap at i is less than heap at max */
        if (heap[i] < heap[max]) {
            swap(heap + i, heap + max);

            /* recursive case */
            return sift_down(heap, max, end);
        }
    
    /* if left is within the heap, and heap at i is less than heap at left */
    } else if (LEFT(i) <= end && heap[i] < heap[LEFT(i)]) {
        swap(heap + i, heap + LEFT(i));
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
