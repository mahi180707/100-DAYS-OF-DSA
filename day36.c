#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int n, m, i, x;

    // number of elements to enqueue
    scanf("%d", &n);

    // enqueue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        if(front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;  // circular increment
        }

        queue[rear] = x;
    }

    // number of dequeues
    scanf("%d", &m);

    // dequeue operations
    for(i = 0; i < m; i++) {
        if(front == -1) {
            printf("Queue is empty\n");
            return 0;
        }

        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    // print queue from front to rear
    if(front != -1) {
        int i = front;
        while(1) {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % MAX;
        }
    }

    return 0;
}