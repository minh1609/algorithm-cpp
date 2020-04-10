#include "AVLTree.h"

using namespace std;

template <typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

template <typename T>
void AVLTree<T>::insert(T value) {
    root = insert(value, root);
}

template <typename T>
void AVLTree<T>::print() {
    inOrder(root);
    cout << endl;
}

template <typename T>
void AVLTree<T>::remove(T x) {
    root = remove(x, root);
}

template <typename T>
void AVLTree<T>::empty() {
    makeEmpty(root);
}

template <typename T>
int AVLTree<T>::height() {
    return root->height;
}
