#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void push_front(int x) {
    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } 
    else {
        front--;
    }
    deque[front] = x;
}

void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } 
    else {
        rear++;
    }
    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } 
    else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } 
    else {
        rear--;
    }
}

int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    pop_front();
    pop_back();

    printf("Front element: %d\n", getFront());
    printf("Rear element: %d\n", getBack());
    printf("Size: %d\n", size());

    display();

    return 0;
}