#include <iostream>

using namespace std;

void hanoi(int n, char from, char tmp, char to) {
    if (n == 1) {
        cout << "move " << from << " to " << to << endl;

        return;
    }
    hanoi(n - 1, from, to, tmp);
    cout << "move " << from << " to " << to << endl;
    hanoi(n - 1, tmp, from, to);
}

void semiHanoi(int n, char A, char B, char C) {
    static int x = 1;

    if (n < 1)
        return;

    if (x == n) {
        hanoi(n, 'A', 'B', 'C');
        return;
    }

    if (n % 2 == 1) {
        if (x % 2 == 1)
            hanoi(x, A, C, B);
        else
            hanoi(x, B, C, A);

    } else {
        if (x % 2 == 1)
            hanoi(x, B, C, A);

        else
            hanoi(x, A, C, B);
    }

    x++;
    semiHanoi(n, 'A', 'B', 'C');
}

int main() {
    semiHanoi(3, 'A', 'B', 'C');
    return 0;
}
