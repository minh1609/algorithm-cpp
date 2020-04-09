#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
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

    //return true if edges contain node e
    bool connectTo(int e) {
        if (from == e || to == e) {
            return true;
        }
        return false;
    }

    bool operator<(const Edge& e) {
        return (weight < e.weight);
    }
};

class Graph {
   public:
    vector<Edge> edges;
    int numberOfNodes;

    //build graph from txt file
    Graph(string fileName) {
        ifstream fin;
        fin.open(fileName);

        string word;

        fin >> word;
        numberOfNodes = stoi(word);

        while (fin >> word) {
            int from = stoi(word);
            fin >> word;
            int to = stoi(word);
            fin >> word;
            int weight = stoi(word);

            Edge e = Edge(from, to, weight);
            edges.push_back(e);
        }

        fin.close();
    }
    void print() {
        for (int i = 0; i < edges.size(); i++) {
            cerr << edges[i].from << " " << edges[i].to << " " << edges[i].weight << endl;
        }
    }

    //apart from edges[position], are there any edges connect to 2 nodes which connect to edges[position]
    bool connect(int position) {
        int node1 = edges[position].from;
        int node2 = edges[position].to;

        bool connectToN1 = false;
        bool connectToN2 = false;

        for (int i = position + 1; i < edges.size(); i++) {
            if (edges[i].connectTo(node1)) {
                connectToN1 = true;
            }

            if (edges[i].connectTo(node2)) {
                connectToN2 = true;
            }
        }
        return connectToN2 & connectToN1;
    }

    void reverseKruskal() {
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());

        int count = 0;

        while (edges.size() > numberOfNodes - 1) {
            if (connect(count)) {
                edges.erase(edges.begin());
            } else {
                edges.push_back(edges[0]);
                edges.erase(edges.begin());
            }
        }
    }
};

int main() {
    Graph g = Graph("sparce7.txt");
    g.print();
    cerr << "Apply algorithm" << endl;
    g.reverseKruskal();
    g.print();

    return 0;
}