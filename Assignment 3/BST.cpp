#include "BST.h"
#include <stack>

using namespace std;

template <typename T>
BST<T>::BST() {
    root = nullptr;
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
BST<T> BST<T>::merge(BST t1, BST t2) {
    BST<T> result;

    stack<T> s1;
    stack<T> s2;

    node* c1 = t1.root;
    node* c2 = t2.root;

    if (t1.root == nullptr) {
        result = t2;
    } else if (t2.root == nullptr) {
        result = t1;
    }

    while (c1 != nullptr || c2 != nullptr || s1.empty() || s2.empty()) {
        if (c1 != nullptr || c2 != nullptr) {
            if (c1 != nullptr) {
                s1.push(c1->data);  //WARNING
                c1 = c1->left;
            }
            if (c2 != nullptr) {
                s2.push(c2->data);  //WARNING
                c2 = c2->left;
            }
        } else {
            if (s1.empty()) {
                while (!s2.empty()) {
                    c2->data = s2.pop();
                    c2->left = nullptr;
                    inorder(c2, result);  //add vector
                }
                return result;
            } else if (!s2.empty()) {
                while (!s1.empty()) {
                    c1->data = s1.pop();
                    c1->left = nullptr;
                    inorder(c1, result);
                }
                return result;
            }
            c1->data = s1.pop();
            c2->data = s2.pop();

            if (c1->data < c2->data) {
                result.insert(c1->data);
                c1 = c1->right;
                s2.push(c2->data);
                c2 = nullptr;
            } else {
                result.insert(c2->data);
                c2 = c2->right;
                s1.push(c1->data);
                c1 = nullptr;
            }
        }
    }
    return result;
}
