#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX_SIZE 1000

struct DaryHeap {
    int *heap;
    int size;
    int d;
};

struct DaryHeap* createDaryHeap(int d) {
    struct DaryHeap* heap = (struct DaryHeap*)malloc(sizeof(struct DaryHeap));
    heap->heap = (int*)malloc(MAX_SIZE * sizeof(int));
    heap->size = 0;
    heap->d = d;
    return heap;
}

int parent(int i, int d) {
    return (i - 1) / d;
}

int child(int i, int k, int d) {
    return d * i + k;
}

void maxHeapify(struct DaryHeap* heap, int i) {
    int largest = i;
    for (int k = 1; k <= heap->d; k++) {
        int c = child(i, k, heap->d);
        if (c < heap->size && heap->heap[c] > heap->heap[largest]) {
            largest = c;
        }
    }
    if (largest != i) {
        int temp = heap->heap[i];
        heap->heap[i] = heap->heap[largest];
        heap->heap[largest] = temp;
        maxHeapify(heap, largest);
    }
}

void insert(struct DaryHeap* heap, int key) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    while (i > 0 && heap->heap[parent(i, heap->d)] < key) {
        heap->heap[i] = heap->heap[parent(i, heap->d)];
        i = parent(i, heap->d);
    }
    heap->heap[i] = key;
}

int extractMax(struct DaryHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->heap[0];
    }
    int max = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return max;
}

void printHeap(struct DaryHeap* heap) {
    printf("D-ary Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
}

void increase_key(int *heap, int i, int key, int d, int size) {
    if (i >= size || i < 0) {
        printf("Index out of bounds\n");
        return;
    }
    if (key < heap[i]) {
        printf("New key is smaller than the current key\n");
        return;
    }
    heap[i] = key;
    int parent_index = (i - 1) / d;
    while (i > 0 && heap[parent_index] < heap[i]) {

        int temp = heap[i];
        heap[i] = heap[parent_index];
        heap[parent_index] = temp;

        i = parent_index;
        parent_index = (i - 1) / d;
    }
}


int main() {
    int d = 3; 
    struct DaryHeap* heap = createDaryHeap(d);
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 10);
    printHeap(heap);
    printf("Extracted max element: %d\n", extractMax(heap));
    printHeap(heap);
    free(heap->heap);
    free(heap);
    return 0;
}
