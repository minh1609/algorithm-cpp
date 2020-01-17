#include <iostream>
#include <string>

using namespace std;

void print(string *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}
//RED, BLUE, WHITE
int main() {
    int arrayLength = 5;
    string *arr = new string[arrayLength];
    arr[0] = "blue";
    arr[1] = "white";
    arr[2] = "red";
    arr[3] = "blue";
    arr[4] = "red";

    print(arr, arrayLength);

    int low = 0;
    int mid = 0;
    int high = arrayLength - 1;

    while (mid <= high) {
        if (arr[mid].compare("red") == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid].compare("blue") == 0) {
            mid++;
        } else {
            swap(arr[mid], arr[high--]);
        }
    }
    cerr << "After sort" << endl;
    print(arr, arrayLength);

    return 0;
}