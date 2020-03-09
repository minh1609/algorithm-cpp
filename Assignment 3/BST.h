#ifndef BST_H
#define BST_H

#include <vector>

using namespace std;

template <typename T>
class BST {
    struct node {
        T data;
        node *left;
        node *right;
    };

    //insert x to node n
    node *insert(T x, node *n) {
        if (n == nullptr) {
            n = new node;
            n->data = x;
            n->left = n->right = nullptr;
        } else if (x < n->data)
            n->left = insert(x, n->left);
        else if (x > n->data)
            n->right = insert(x, n->right);
        return n;
    }

    node *findMin(node *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    node *remove(int x, node *n) {
        node *tmp;
        if (n == nullptr)
            return nullptr;
        else if (x < n->data)
            n->left = remove(x, n->left);
        else if (x > n->data)
            n->right = remove(x, n->right);
        else if (n->left && n->right) {
            tmp = findMin(n->right);
            n->data = tmp->data;
            n->right = remove(n->data, n->right);
        } else {
            tmp = n;
            if (n->left == nullptr)
                n = n->right;
            else if (n->right == nullptr)
                n = n->left;
            delete tmp;
        }

        return n;
    }

    int height(node *node) {
        if (node == nullptr)
            return 0;
        else {
            int leftH = height(node->left);
            int rightH = height(node->right);

            if (leftH > rightH)
                return (leftH + 1);
            else
                return (rightH + 1);
        }
    }

    //traverse node n inorder
    void inorder(node *n) {
        if (n == nullptr)
            return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }

    void inorder(node *n, BST<T> t) {
        if (n == nullptr)
            return;
        inorder(n->left);
        t.insert(n->data);
        inorder(n->right);
    }

   public:
    node *root;
    BST();
    // ~BST();
    BST(T);
    void insert(T);
    void remove(T);
    void print();
    int maxHeight();
    BST merge(BST t1, BST t2);
};

#endif