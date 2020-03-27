#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Hash.cpp"

using namespace std;

int main() {
    Hash h1("keys1.txt");

    h1.buildHashTable(0);
    cerr << "String length: " << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(1);
    cerr << "First character: " << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(2);
    cerr << "Additive: " << h1.calculateDiff() << endl;
    h1.cleanTable();
    h1.buildHashTable(3);
    cerr << "Mystery: " << h1.calculateDiff() << endl;
    h1.cleanTable();

    return 0;
    //Sometime, it might stop at h1.buildHashTable(3);
    //Just re run again
}