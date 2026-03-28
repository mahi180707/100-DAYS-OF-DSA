#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create Node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build Tree (level order array)
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Store vertical order
void verticalOrder(struct Node* root, int hd, int map[MAX][MAX], int count[MAX]) {
    if (root == NULL)
        return;

    int index = hd + MAX/2; // shift to avoid negative index

    map[index][count[index]++] = root->data;

    verticalOrder(root->left, hd - 1, map, count);
    verticalOrder(root->right, hd + 1, map, count);
}

// Print result
void printVertical(int map[MAX][MAX], int count[MAX]) {
    for (int i = 0; i < MAX; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int map[MAX][MAX] = {0};
    int count[MAX] = {0};

    verticalOrder(root, 0, map, count);

    printVertical(map, count);

    return 0;
}