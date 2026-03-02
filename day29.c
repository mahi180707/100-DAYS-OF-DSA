#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

// Rotate list
struct Node* rotateRight(struct Node* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    
    struct Node* temp = head;
    int length = 1;
    
    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    
    k = k % length;
    if (k == 0)
        return head;
    
    // Make circular
    temp->next = head;
    
    int steps = length - k;
    struct Node* newTail = head;
    
    // Move to (n-k)th node
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;
    
    struct Node* newHead = newTail->next;
    
    // Break circle
    newTail->next = NULL;
    
    return newHead;
}

// Traverse list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, k;
    struct Node* head = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    
    scanf("%d", &k);
    
    head = rotateRight(head, k);
    
    printList(head);
    
    return 0;
}