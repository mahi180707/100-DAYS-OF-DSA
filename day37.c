#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Function to insert an element in priority queue
void insert(int x) {
    pq[size] = x;
    size++;
}

// Function to delete the element with highest priority (smallest value)
int delete() {
    if (size == 0) return -1;

    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[min_index])
            min_index = i;
    }

    int deleted = pq[min_index];

    // Shift elements left
    for (int i = min_index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;

    return deleted;
}

// Function to peek at the element with highest priority
int peek() {
    if (size == 0) return -1;

    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[min_index])
            min_index = i;
    }

    return pq[min_index];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}