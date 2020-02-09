#ifndef ER_H
#define ER_H

using namespace std;

#include <queue>

template <typename T>
class ER {
   private:
    priority_queue<T> q;

   public:
    // ~ER();
    ER();
    void insert(T unit);
    void remove();
    void print();
};

#endif
