#include "ER.h"

using namespace std;

template <typename T>
ER<T>::ER() {
}

template <typename T>
ER<T>::~ER() {
    q.empty();
}

template <typename T>
void ER<T>::insert(T unit) {
    q.push(unit);
}

template <typename T>
void ER<T>::remove() {
    q.pop();
}

template <typename T>
void ER<T>::print() {
    priority_queue<T> tmp = q;
    while (!tmp.empty()) {
        cout << " " << tmp.top();
        tmp.pop();
    }
    cout << endl;
}
