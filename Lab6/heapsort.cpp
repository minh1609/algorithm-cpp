using namespace std;
#include <iostream>

void heapify(int arr[], int n, int root) {
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int high = root;

    if (left < n && arr[left] > arr[high])
        high = left;

    if (right < n && arr[right] > arr[high])
        high = right;

    if (high != root) {
        swap(arr[root], arr[high]);
        heapify(arr, n, high);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main() {
    int arr[] = {15, 7, 13, 2, 1, 20};
    heapSort(arr, 6);
    print(arr, 6);
}