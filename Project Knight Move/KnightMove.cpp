
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// structure for storing a cell's data
class Cell {
   public:
    int x, y;
    int dis;
    Cell() {}
    Cell(int x, int y, int dis) {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
    void print() {
        cerr << "[" << x << "," << y << "]" << endl;
    }
};

// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y) {
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
        return true;
    return false;
}

// Method returns minimum step to reach target position
int minStepToReachTarget(int knightPosition[], int target[]) {
    // x and y direction, where a knight can move
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    // queue for storing states of knight in board
    queue<Cell> q;

    // push starting position of knight with 0 distance
    q.push(Cell(knightPosition[0], knightPosition[1], 0));

    Cell t;
    int x, y;
    bool visit[8][8];

    fill((bool*)visit, (bool*)visit + sizeof(visit) / sizeof(bool), 0);

    //set knight initial position is visited
    visit[knightPosition[0]][knightPosition[1]] = true;

    // loop untill we have one element in queue
    while (!q.empty()) {
        t = q.front();
        q.pop();

        // if current cell is equal to target cell,
        // return its distance
        if (t.x == target[0] && t.y == target[1]) {
            return t.dis;
        }

        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];

            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(Cell(x, y, t.dis + 1));
            }
        }
    }
}

int main() {
    int knightPos[] = {3, 3};
    int targetPos[] = {4, 3};
    cout << minStepToReachTarget(knightPos, targetPos);

    return 0;
}