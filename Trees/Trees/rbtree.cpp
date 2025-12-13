#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data)
        : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    Node *root;

    void rotateLeft(Node *&pt) {
        Node *rightChild = pt->right;
        pt->right = rightChild->left;

        if (pt->right)
            pt->right->parent = pt;

        rightChild->parent = pt->parent;

        if (!pt->parent)
            root = rightChild;
        else if (pt == pt->parent->left)
            pt->parent->left = rightChild;
        else
            pt->parent->right = rightChild;

        rightChild->left = pt;
        pt->parent = rightChild;
    }

    void rotateRight(Node *&pt) {
        Node *leftChild = pt->left;
        pt->left = leftChild->right;

        if (pt->left)
            pt->left->parent = pt;

        leftChild->parent = pt->parent;

        if (!pt->parent)
            root = leftChild;
        else if (pt == pt->parent->left)
            pt->parent->left = leftChild;
        else
            pt->parent->right = leftChild;

        leftChild->right = pt;
        pt->parent = leftChild;
    }

    void fixViolation(Node *&pt) {
        Node *parent = nullptr;
        Node *grandparent = nullptr;

        while ((pt != root) && (pt->color != BLACK) &&
               (pt->parent->color == RED)) {

            parent = pt->parent;
            grandparent = pt->parent->parent;

            if (parent == grandparent->left) {
                Node *uncle = grandparent->right;

                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                }

                else {
                    if (pt == parent->right) {
                        rotateLeft(parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    pt = parent;
                }
            }

            else {
                Node *uncle = grandparent->left;

                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                }

                else {
                    if (pt == parent->left) {
                        rotateRight(parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    pt = parent;
                }
            }
        }
        root->color = BLACK;
    }

public:
    RBTree() { root = nullptr; }

    void insert(const int &data) {
        Node *pt = new Node(data);
        root = BSTInsert(root, pt);
        fixViolation(pt);
    }

    Node *BSTInsert(Node *root, Node *pt) {
        if (!root)
            return pt;

        if (pt->data < root->data) {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        }
        else if (pt->data > root->data) {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }
        return root;
    }
};

int main() {
    RBTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    return 0;
}
