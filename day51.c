#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both values are greater → go right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Otherwise root is LCA
    return root;
}

int main() {
    int n, x, n1, n2;
    struct Node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST values
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Input nodes to find LCA
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}