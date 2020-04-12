
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
    vector<Cell> path;

    Cell() {}
    Cell(int x, int y, int dis) {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
    void print() {
        cerr << "[" << x << "," << y << "] dis: " << dis << endl;
    }
};

void printVector(vector<Cell> v) {
    cerr << "#####" << endl;
    for (int i = 0; i < v.size(); i++) {
        v[i].print();
    }
    cerr << "#####" << endl;
}

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
    vector<Cell> q;

    // push starting position of knight with 0 distance
    q.push_back(Cell(knightPosition[0], knightPosition[1], 0));

    Cell temp;
    int x, y;
    bool visit[8][8];

    fill((bool*)visit, (bool*)visit + sizeof(visit) / sizeof(bool), 0);

    //set knight initial position is visited
    visit[knightPosition[0]][knightPosition[1]] = true;

    // loop untill we have one element in queue
    while (!q.empty()) {
        temp = q[0];
        temp.print();
        q.erase(q.begin());

        // if current cell is equal to target cell,
        // return its distance
        if (temp.x == target[0] && temp.y == target[1]) {
            return temp.dis;
        }

        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = temp.x + dx[i];
            y = temp.y + dy[i];

            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y) && !visit[x][y]) {
                visit[x][y] = true;
                q.push_back(Cell(x, y, temp.dis + 1));
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