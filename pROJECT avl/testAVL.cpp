#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "AVLTree.cpp"

using namespace std;

int getInput() {
    srand(time(0));
    int num = rand() % 15 + 5;
    return num;
}

void genInputFile(int n, string filename) {
    ofstream fout;
    fout.open(filename);
    fout << n;

    for (int i = 0; i < n; i++) {
        int num = rand() % 2000 + 1;
        fout << "\n"
             << num;
    }
    fout.close();
}

AVLTree<int>* BuildAVLTree(string filename) {
    AVLTree<int>* tree = new AVLTree<int>();
    ifstream fin;
    fin.open(filename);
    string word;

    fin >> word;
    while (fin >> word) {
        int number = stoi(word);
        tree->insert(number);
    }
    fin.close();

    return tree;
}

template <typename T>
void DeleteAVLTree(AVLTree<T>* tree) {
    tree->empty();
}

void InsertNodeAVL(AVLTree<int>* tree, int element) {
    tree->insert(element);
}

void DeleteNodeAVL(AVLTree<int>* tree, int element) {
    tree->remove(element);
}
template <typename T>
void printAVL(AVLTree<T>* tree) {
    tree->print();
}

int main() {
    int n = getInput();
    genInputFile(n, "text.txt");
    AVLTree<int>* avl = BuildAVLTree("text.txt");

    cout << "height of AVL tree is:" << avl->height() << endl;
    printAVL(avl);

    // int node;
    // cout << "Enter a value to insert: ";
    // cin >> node;
    // InsertNodeAVL(avl, node);
    // cout << "height of AVL tree is:" << avl->height() << endl;
    // printAVL(avl);

    // cout << "Enter a value to delete: ";
    // cin >> node;
    // DeleteNodeAVL(avl, node);
    // cout << "height of AVL tree is:" << avl->height() << endl;
    // printAVL(avl);

    // DeleteAVLTree(avl);
    // printAVL(avl);

    return 0;
}