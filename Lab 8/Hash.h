#ifndef HASH_H
#define HASH_H

#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Hash {
   public:
    Hash(string fileName);

    //method = 0: string length, 1: first character, ...
    void buildHashTable(int method);
    int calculateDiff();
    //fill all spots on table with 0
    void cleanTable();

   private:
    const int SIZE = (int)pow(2, 16);
    vector<int> hashTable = vector<int>(SIZE, 0);
    vector<string> list;
    int length(string str) { return str.size() % SIZE; }
    int firstCharacter(string str) { return (int)str[0] % SIZE; }
    int additive(string str) {
        int result = 0;
        for (int i = 0; i < str.size(); i++) {
            int x = (int)str[i];
            result = result + x;
        }
        return result % SIZE;
    }
    int mystery(string str) {
        return (additive(str) * firstCharacter(str)) % SIZE;
    }

    int bonus(string str) {
    }
    //hash table store how many time hash function give same result for diff strings
};

#endif