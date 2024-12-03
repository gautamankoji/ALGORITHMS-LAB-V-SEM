# EX 16: Implement AVL Tree and it's Operations

## Introduction

An AVL tree is a self-balancing binary search tree where the difference between the heights of the left and right subtrees (balance factor) of every node is at most 1. If, at any time during an insertion or deletion, the balance factor becomes greater than 1 or less than -1, the tree is rebalanced using rotations.

This implementation provides the basic operations for AVL trees: insertion, deletion, and in-order traversal.

## Algorithm

1. **Insertion**:
   - Insert the node like a normal binary search tree (BST) insertion.
   - After insertion, update the height of the current node.
   - Balance the tree by performing rotations if needed.

2. **Deletion**:
   - Perform standard BST deletion.
   - After deletion, update the height of the current node.
   - Balance the tree by performing rotations if needed.

3. **Rotations**:
   - **Left Rotation**: Applied when the right subtree is taller.
   - **Right Rotation**: Applied when the left subtree is taller.
   - **Left-Right Rotation**: Combination of left and right rotations.
   - **Right-Left Rotation**: Combination of right and left rotations.

## Implementation

```cpp
#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
};

int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* createNode(int key) {
    Node* node = new Node{key, 1, nullptr, nullptr};
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return createNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    while (node->left) node = node->left;
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (!root) return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-order traversal of the AVL tree:\n";
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 20);
    cout << "In-order traversal after deleting 20:\n";
    inOrder(root);
    cout << endl;

    return 0;
}
```

### Output

```powershell
In-order traversal of the AVL tree:
10 20 25 30 40 50
In-order traversal after deleting 20:
10 25 30 40 50
```

### Explanation

### 1. **Insertion**

- A new node is inserted into the tree like a normal binary search tree insertion.
- After insertion, the height of the node is updated.
- The balance factor of the node is calculated. If the balance factor is more than 1 or less than -1, rotations are performed.

### 2. **Deletion**

- The node is deleted using the standard BST deletion approach.
- If the node has two children, the in-order successor is used to replace it.
- After deletion, the balance factor is checked and rotations are performed if necessary.

### 3. **Rotations**

- **Left and Right Rotations** are used to restore the balance of the tree after insertion or deletion.
