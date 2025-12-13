#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int height(Node *n) {
    return n ? n->height : 0;
}

int getBalance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rotateRight(Node *y) {
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* rotateLeft(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insertNode(Node *node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 15);

    cout << "AVL Inorder: ";
    inorder(root);
}
