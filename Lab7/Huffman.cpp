
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

void makeHuffmanTree(vector<char> data, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, NodeCompare> q;

    for (int i = 0; i < data.size(); i++) {
        Node* newNode = new Node(data[i], freq[i]);
        q.push(newNode);
    }

    Node* root = generateTree(q);

    int arr[50], top = 0;
    printTrie(root, arr, top);
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cerr << v[i] << " ";
    }
}

int main() {
    string str = "EYEWITNESSNEWS";
    vector<char> data;
    vector<int> freq;

    for (int i = 0; i < str.size(); i++) {
        if (count(data.begin(), data.end(), str[i]) > 0) {
            //
        } else {
            data.push_back(str[i]);
        }
    }

    for (int i = 0; i < data.size(); i++) {
        int f = count(str.begin(), str.end(), data[i]);
        freq.push_back(f);
    }

    makeHuffmanTree(data, freq);
    return 0;
}