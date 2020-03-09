#include <ctime>
#include <iostream>
#include <vector>

#include "BST.cpp"

using namespace std;

template <typename T>
vector<T> genData(T n) {
    vector<int> list;
    if (n <= 0) {
        return list;
    }
    srand(time(0));
    for (int i = 1; i <= n; i++) {
        int random = -n + (rand() % static_cast<int>(n + n + 1));
        list.push_back(random);
        // cerr << random;
    }
}

template <typename T>
BST<T> makeBST(vector<T> v) {
    BST<int> bst;
    for (int i = 0; i < v.size(); i++) {
        bst.insert(v[i]);
    }

    return bst;
}

template <typename T>
void printBST(BST<T> bst) {
    bst.print();
}

template <typename T>
int height(BST<T> bst) {
    return bst.maxHeight();
}

template <typename T>
void remove(T key, BST<T> t) {
    t.remove(key);
}

template <typename T>
BST<T> mergeBST(BST<T> t1, BST<T> t2) {
    return t1.merge(t1, t2);
}

int main() {
    // // declaration of your variables ...
    // n1 = getInput();      // either generates a random non-negative
    //                       // integer or reads it from input
    // list1 = genData(n1);  //generates a list of n1 random numbers [-n1, n1]
    // cout << "The List1: ";
    // printList(list1);  //prints elements of the given list
    // n2 = getInput();
    // list2 = genData(n2);  //generates a list of n2 random numbers [-n2, n2]
    // printList(list2);
    // bst1 = makeBST(list1);
    // cout << "In-order traversal of bst1 is: ";
    // printBT(bst1);
    // remove(list1[n1 / 2], bst1);  // removes list1[n1/2] from corresponding tree (bst1)

    // cout << "In-order traversal of bst1 after deleting " << list1[n1 / 2] << " is: ";
    // printBT(bst1);
    // bst2 = makeBST(list2);
    // cout << "In-order traversal of bst2 is: ";
    // printBT(bst2);
    // bst3 = mergeBST(bst1, bst2);
    // cout << "In_order traversal of bst3 is: ";
    // printBT(bst3);
    // cout << "The height of bst1 is " << height(bst1) << endl;
    // cout << "The height of bst2 is " << height(bst2) << endl;
    // cout << "The height of merged tree is " << height(bst3) << endl;
    // string infix = getExpression();  // read infix expression from input
    // bt4 = infixExprTree(infix);
    // cout << "In-order traversal of bt4 is: ";
    // printBT(bt4);
    // cout << "The postfix expression is " << InfixPostfixExpr(infix) << endl;

    BST<int> t;
    BST<int> t2;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);

    t2.insert(12);
    t2.insert(2);
    t2.insert(17);
    t2.insert(16);
    t2.insert(1);

    cerr << height(t);
    mergeBST(t, t2);

    return 0;
}