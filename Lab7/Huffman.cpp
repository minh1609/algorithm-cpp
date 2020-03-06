
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char data;
    int f;
    Node* left;
    Node* right;
    Node(char ch, int f) {
        data = ch;
        f = f;
        left = right = NULL;
    }
};

struct NodeCompare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

Node* generateTree(priority_queue<Node*, vector<Node*>, NodeCompare> q) {
    while (q.size() > 1) {
        Node* left = q.top();
        q.pop();
        Node* right = q.top();
        q.pop();

        Node* node = new Node('$', left->f + right->f);
        node->left = left;
        node->right = right;
        q.push(node);
    }

    return q.top();
}

void printTrie(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printTrie(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printTrie(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        cout << root->data << ": ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
}

void makeHuffmanTree(char data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, NodeCompare> q;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node(data[i], freq[i]);
        q.push(newNode);
    }

    Node* root = generateTree(q);

    int arr[50], top = 0;
    printTrie(root, arr, top);
}

void printVector(vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        cerr << v[i] << " ";
    }
}

int main() {
    string str = "EYEWITNESSNEWS";
    vector<char> v;

    for (int i = 0; i < str.size(); i++) {
        if (count(v.begin(), v.end(), str[i]) > 0) {
            cerr << "dd";
        } else {
            v.push_back(str[i]);
        }
    }

    //printVector(v);
    char data[v.size()];

    // char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    // int freq[] = {5, 9, 12, 13, 16, 45};
    // int size = sizeof(data) / sizeof(data[0]);

    // makeHuffmanTree(data, freq, size);
    return 0;
}