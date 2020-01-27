#include <iostream>
#include <string>
using namespace std;

int numPathsFromHome(int street, int avenue) {
    if (street == 0 || avenue == 0) {
        return 1;
    }
    return numPathsFromHome(street - 1, avenue) + numPathsFromHome(street, avenue - 1);
}

string removeLastChar(string str) {
    return str.substr(0, str.size() - 1);
}

bool hasSubsequence(const string& T, const string& S) {
    if (T.length() == 0) return true;
    if (S.length() == 0) return false;

    if (T[T.length() - 1] == S[S.length() - 1]) {
        return hasSubsequence(removeLastChar(T), removeLastChar(S));
    }
    return hasSubsequence(T, removeLastChar(S));
}

int main() {
    cerr << numPathsFromHome(2, 1) << endl;
    cerr << numPathsFromHome(4, 2) << endl;
    cerr << hasSubsequence("pin", "programming") << endl;
    cerr << hasSubsequence("steal", "least") << endl;
    return 0;
}