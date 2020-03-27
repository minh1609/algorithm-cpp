
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Edge {
   public:
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};

bool keepTrack(vector<Edge> v, int f, int t) {
    for (int i = 0; i < v.size(); i++) {
        if ((v.at(i).from == t && v.at(i).to == f) || (v.at(i).to == f && v.at(i).from == t)) {
            return true;
        }
    }
    return false;
}

void printList(vector<vector<int> > list, int number) {
    // for (int i = 0; i < number; i++) {
    //     cout << "index " << i << ": {";
    //     for (int j = 0; i < list[i].size(); j++) {
    //         int x = list[i][j];
    //         cout << x << ",";
    //     }

    //     cout << "}" << endl;
    // }

    for (int i = 0; i < list.size(); i++) {
        cout << "index " << i << ": {";

        for (int j = 0; j < list[i].size(); j++) {
            cout << list[i][j] << " ";
        }
    }
}

void printedges(vector<Edge> v) {
    cout << "Edges: " << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << "Weight " << v[i].weight << ": (" << v[i].from << "," << v[i].to << ")" << endl;
    }
    cout << endl;
}

void printGraph(string filename, vector<Edge> v) {
    fstream file;
    file.open("sample.txt", ios::out);
    file << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        file << v[i].from << " " << v[i].to << " " << v[i].weight << endl;
    }
    file.close();
}

void makeSparseUDWG(int n) {
    srand(time(0));

    if (n <= 10) return;
    int edgeC = rand() % (2 * n) + 1;

    vector<Edge> ve;
    vector<vector<int> > result(edgeC, vector<int>(0));
    srand(time(0));
    int count = 0;

    while (count < edgeC) {
        int f = rand() % n;
        int s = rand() % n;
        int w = rand() % 99 + 1;
        if (!keepTrack(ve, f, s) && f != s) {
            Edge e1(f, s, w);
            ve.push_back(e1);
            count++;
        }
    }
    printedges(ve);
    printGraph("sample.txt", ve);

    for (int i = 0; i < edgeC; i++) {
        Edge temp = ve.at(i);
        int source = temp.from;
        int dest = temp.to;
        result[source].push_back(dest);
        result[dest].push_back(source);
    }
    printList(result, n);
    cout << endl;
}

void makeDenseDWG(int n) {
    if (n < 10) return;

    int start = ((n - 2) * n) / 2;
    int totalEdge = rand() % 50 + start;

    vector<vector<int> > matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    vector<Edge> ve;
    srand(time(0));
    int count = 0;
    while (count < totalEdge) {
        int f = rand() % n;
        int t = rand() % n;
        int w = rand() % 99 + 1;

        if (matrix[f][t] != 1) {
            Edge e1(f, t, w);
            ve.push_back(e1);
            matrix[f][t] = 1;
            count++;
        }
    }
    printedges(ve);

    cout << "  ";
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i << "|";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //makeSparseUDWG(11);
    makeDenseDWG(11);

    int def[4][3];

    return 0;
}