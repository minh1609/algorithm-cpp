#include "Hash.h"
#include <fstream>

using namespace std;

Hash::Hash(string fileName) {
    fstream fin;
    fin.open(fileName);
    string line = "";
    int i = 0;

    while (!fin.eof()) {
        getline(fin, line);
        list.push_back(line);
    }
    fin.close();
}

void Hash::buildHashTable(int method) {
    for (int i = 0; i < list.size(); i++) {
        int hash;

        if (method == 0) {
            hash = length(list[i]);
        } else if (method == 1) {
            hash = firstCharacter(list[i]);
        } else if (method == 2) {
            hash = additive(list[i]);
        } else if (method == 3) {
            hash = mystery(list[i]);
        } else if (method == 4) {
            hash = bonus(list[i]);
        }
        hashTable[hash]++;
    }
}

int Hash::calculateDiff() {
    int min = 0;
    int max = 0;
    for (int i = 0; i < hashTable.size(); i++) {
        if (hashTable[i] > max) max = hashTable[i];
        if (hashTable[i] < min) min = hashTable[i];
    }
    return max - min;
}

void Hash::cleanTable() {
    fill(hashTable.begin(), hashTable.end(), 0);
}
