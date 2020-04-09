
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

void printEdges(vector<Edge> v) {
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
    int totalEdge = rand() % (2 * n) + 1;

    vector<Edge> edgeList;
    vector<vector<int> > result(totalEdge, vector<int>(0));
    srand(time(0));
    int count = 0;

    while (count < totalEdge) {
        int f = rand() % n;
        int s = rand() % n;
        int w = rand() % 99 + 1;
        if (!keepTrack(edgeList, f, s) && f != s) {
            Edge e1(f, s, w);
            edgeList.push_back(e1);
            count++;
        }
    }
    printEdges(edgeList);
    printGraph("sample.txt", edgeList);

    for (int i = 0; i < totalEdge; i++) {
        Edge temp = edgeList.at(i);
        int source = temp.from;
        int dest = temp.to;
        result[source].push_back(dest);
        result[dest].push_back(source);
    }
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
    vector<Edge> edgeList;
    srand(time(0));
    int count = 0;
    while (count < totalEdge) {
        int f = rand() % n;
        int t = rand() % n;
        int w = rand() % 99 + 1;

        if (matrix[f][t] != 1) {
            Edge e(f, t, w);
            edgeList.push_back(e);
            matrix[f][t] = 1;
            count++;
        }
    }
    printEdges(edgeList);

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
    cerr << "Part b" << endl;
    makeDenseDWG(11);

    cerr << "Part a c" << endl;
    makeSparseUDWG(11);

    return 0;
}