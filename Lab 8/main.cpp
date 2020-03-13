#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Hash.cpp"

using namespace std;

void readFile(string fileName, vector<string>& v) {
    fstream fin;
    fin.open(fileName);
    string line = "";
    int i = 0;

    while (!fin.eof()) {
        getline(fin, line);
        v.push_back(line);
    }

    fin.close();
}

void printVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cerr << v[i] << endl;
    }
}

int main() {
    //For some compiler, this code might sometime stop at h1.buildHashTable(3);
    //Just re run again

    Hash h1("keys1.txt");

    h1.buildHashTable(0);
    cerr << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(1);
    cerr << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(2);
    cerr << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(3);
    cerr << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(4);
    cerr << h1.calculateDiff() << endl;
    h1.cleanTable();

    return 0;
    //For some compiler, this code might sometime stop at h1.buildHashTable(3);
    //Just re run again
}