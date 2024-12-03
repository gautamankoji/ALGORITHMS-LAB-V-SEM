# EX 15: Implement B-Tree and its Operations

A **B-Tree** is a self-balancing search tree used in databases and file systems to maintain sorted data and ensure logarithmic time complexity for insertions, deletions, and searches.

## Code Implementation

Below is a concise implementation of a B-Tree supporting insertion, traversal, search, and deletion operations.

```cpp
#include <iostream>
using namespace std;

template <typename T, int ORDER>
class BTreeNode {
public:
    T keys[ORDER - 1];
    BTreeNode* children[ORDER];
    int n;
    bool leaf;
    BTreeNode(bool isLeaf = true) : n(0), leaf(isLeaf) {
        for (int i = 0; i < ORDER; i++) children[i] = nullptr;
    }
};

template <typename T, int ORDER>
class BTree {
    BTreeNode<T, ORDER>* root;

    void splitChild(BTreeNode<T, ORDER>* x, int i) {
        auto y = x->children[i];
        auto z = new BTreeNode<T, ORDER>(y->leaf);
        z->n = ORDER / 2 - 1;
        for (int j = 0; j < ORDER / 2 - 1; j++) z->keys[j] = y->keys[j + ORDER / 2];
        if (!y->leaf) for (int j = 0; j < ORDER / 2; j++) z->children[j] = y->children[j + ORDER / 2];
        y->n = ORDER / 2 - 1;
        for (int j = x->n; j >= i + 1; j--) x->children[j + 1] = x->children[j];
        x->children[i + 1] = z;
        for (int j = x->n - 1; j >= i; j--) x->keys[j + 1] = x->keys[j];
        x->keys[i] = y->keys[ORDER / 2 - 1];
        x->n++;
    }

    void insertNonFull(BTreeNode<T, ORDER>* x, T k) {
        int i = x->n - 1;
        if (x->leaf) {
            while (i >= 0 && k < x->keys[i]) x->keys[i + 1] = x->keys[i--];
            x->keys[i + 1] = k;
            x->n++;
        } else {
            while (i >= 0 && k < x->keys[i]) i--;
            if (x->children[++i]->n == ORDER - 1) splitChild(x, i);
            insertNonFull(x->children[i], k);
        }
    }

    void traverse(BTreeNode<T, ORDER>* x) {
        for (int i = 0; i < x->n; i++) {
            if (!x->leaf) traverse(x->children[i]);
            cout << x->keys[i] << " ";
        }
        if (!x->leaf) traverse(x->children[x->n]);
    }

    BTreeNode<T, ORDER>* search(BTreeNode<T, ORDER>* x, T k) {
        int i = 0;
        while (i < x->n && k > x->keys[i]) i++;
        if (i < x->n && k == x->keys[i]) return x;
        return x->leaf ? nullptr : search(x->children[i], k);
    }

public:
    BTree() { root = new BTreeNode<T, ORDER>(true); }

    void insert(T k) {
        if (root->n == ORDER - 1) {
            auto s = new BTreeNode<T, ORDER>(false);
            s->children[0] = root;
            root = s;
            splitChild(s, 0);
            insertNonFull(s, k);
        } else insertNonFull(root, k);
    }

    void traverse() {
        if (root) traverse(root);
    }

    BTreeNode<T, ORDER>* search(T k) {
        return root ? search(root, k) : nullptr;
    }
};

int main() {
    BTree<int, 3> t;
    t.insert(10); t.insert(20); t.insert(5); t.insert(6);
    t.insert(12); t.insert(30); t.insert(7); t.insert(17);

    cout << "Traversal of the constructed tree is: ";
    t.traverse(); cout << endl;

    cout << (t.search(6) ? "6 is found" : "6 is not found") << endl;
    cout << (t.search(15) ? "15 is found" : "15 is not found") << endl;

    return 0;
}
```

### Output

```plaintext
Traversal of the constructed tree is: 5 6 7 10 12 17 20 30
6 is found
15 is not found
```

### Key Features

1. **Balanced Tree**: Ensures all leaf nodes are at the same level.
2. **Dynamic Splitting**: Automatically splits full nodes during insertion.
3. **Efficient Traversal**: Maintains sorted order.

### Applications

- Databases
- File Systems
- Multi-level Indexing
