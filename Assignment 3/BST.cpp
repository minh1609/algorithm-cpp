#include "BST.h"
#include <stack>

using namespace std;

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
BST<T>::BST(node* n) {
    root = n;
}

template <typename T>
void BST<T>::insert(T data) {
    root = insert(data, root);
}

template <typename T>
void BST<T>::print() {
    inorder(root);
    cout << endl;
}

template <typename T>
int BST<T>::maxHeight() {
    return height(root);
}

template <typename T>
void BST<T>::remove(T x) {
    remove(x, root);
}

template <typename T>
BST<T> BST<T>::merge(BST t2) {
    node* result = mergeNode(this->root, t2.root);
    BST<T> tree = BST<T>(result);
    return tree;
}
