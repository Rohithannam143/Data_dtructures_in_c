#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Function to create a new node
AVLNode* createNode(int key) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->height = 1;  // initial height
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to get the height of a node
int height(AVLNode* node) {
    return node ? node->height : 0;
}

// Function to rotate right
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = (height(y->left) > height(y->right)) ? height(y->left) + 1 : height(y->right) + 1;
    x->height = (height(x->left) > height(x->right)) ? height(x->left) + 1 : height(x->right) + 1;
    return x;
}

// Function to insert a node into the AVL tree
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);

    node->height = (height(node->left) > height(node->right)) ? height(node->left) + 1 : height(node->right) + 1;

    // Balancing the node
    int balance = height(node->left) - height(node->right);
    if (balance > 1 && key < node->left->key) return rotateRight(node);

    return node;
}

// Function for AVL in-order traversal
void inorder(AVLNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    AVLNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);  // This will cause a right rotation

    printf("AVL Tree In-order traversal: ");
    inorder(root);
    return 0;
}

