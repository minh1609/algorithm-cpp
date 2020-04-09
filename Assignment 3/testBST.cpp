#include <ctime>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "BST.cpp"

using namespace std;

string getExpression() {
    string str;
    cerr << "Enter infix expression";
    cin >> str;
    return str;
}

int getInput() {
    srand(time(0));
    int num = (rand() % (10 - 2 + 1)) + 2;
    return 5;
}

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
void printBT(BST<T> bst) {
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
    return t1.merge(t2);
}

template <typename T>
void printList(vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        cerr << v[i] << " ";
    }
    cerr << endl;
}

//EXPRESSION TREE
int priority(char c) {
    if (c == '*' || c == '/')
        return 1;
    else if (c == '+' || c == '-')
        return 0;
    else
        return -1;
}
string InfixPostfixExpr(string str) {
    stack<char> s;
    s.push('A');
    int l = str.length();
    string result;
    for (int i = 0; i < l; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            result += str[i];

        else if (str[i] == '(')

            s.push('(');

        else if (str[i] == ')') {
            while (s.top() != 'A' && s.top() != '(') {
                char c = s.top();
                s.pop();
                result += c;
            }
            if (s.top() == '(') {
                char c = s.top();
                s.pop();
            }
        }

        else {
            while (s.top() != 'A' && priority(str[i]) <= priority(s.top())) {
                char c = s.top();
                s.pop();
                result += c;
            }
            s.push(str[i]);
        }
    }
    while (s.top() != 'A') {
        char c = s.top();
        s.pop();
        result += c;
    }

    return result;
}

int main() {
    // declaration of your variables ...
    int n1 = getInput();              // either generates a random non-negative
                                      // integer or reads it from input
    vector<int> list1 = genData(n1);  //generates a list of n1 random numbers [-n1, n1]
    cout << "The List1: ";
    printList(list1);  //prints elements of the given list
    int n2 = getInput();
    vector<int> list2 = genData(n2);  //generates a list of n2 random numbers [-n2, n2]
    printList(list2);
    BST<int> bst1 = makeBST(list1);
    cout << "In-order traversal of bst1 is: ";
    printBT(bst1);
    remove(list1[n1 / 2], bst1);  // removes list1[n1/2] from corresponding tree (bst1)

    cout << "In-order traversal of bst1 after deleting " << list1[n1 / 2] << " is: ";
    printBT(bst1);
    BST<int> bst2 = makeBST(list2);
    cout << "In-order traversal of bst2 is: ";
    printBT(bst2);
    BST<int> bst3 = mergeBST(bst1, bst2);
    cout << "In_order traversal of bst3 is: ";
    printBT(bst3);
    cout << "The height of bst1 is " << height(bst1) << endl;
    cout << "The height of bst2 is " << height(bst2) << endl;
    cout << "The height of merged tree is " << height(bst3) << endl;
    string infix = getExpression();  // read infix expression from input

    //3A NOT COMPLETE
    // bt4 = infixExprTree(infix);
    // cout << "In-order traversal of bt4 is: ";
    // printBT(bt4);

    cout << "The postfix expression is " << InfixPostfixExpr(infix) << endl;

    return 0;
}