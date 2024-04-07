#include <bits/stdc++.h>
using namespace std;

int parent[100005];
vector<int> present;
int edge;

struct Edge {
    int src, dest, weight;
} edges[100005];

bool compareEdges(Edge x, Edge y) {
    return x.weight < y.weight;
}

void initialize(int n) {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

int mergeFirst(int i, int sum) {
    int x, y;
    x = findParent(edges[i].src);
    y = findParent(edges[i].dest);
    if (x != y) {
        parent[x] = y;
        present.push_back(i);
        sum += edges[i].weight;
    }
    return sum;
}

int mergeSecond(int i, int sum) {
    int x, y;
    x = findParent(edges[i].src);
    y = findParent(edges[i].dest);
    if (x != y) {
        parent[x] = y;
        sum += edges[i].weight;
        edge++;
    }
    return sum;
}

int main() {
    freopen("input_Q3.txt", "r", stdin); // Redirects standard input to "input.txt"
    freopen("output_Q3.txt", "w", stdout); // Redirects standard output to "out.txt"

    int V, E;
    cin >> V >> E;

    initialize(V);

    vector<int> source(E), destination(E), weights(E);
    for (int i = 0; i < E; i++) {
        cin >> source[i] >> destination[i] >> weights[i];
    }

    for (int i = 0; i < E; i++) {
        edges[i].src = source[i];
        edges[i].dest = destination[i];
        edges[i].weight = weights[i];
    }

    sort(edges, edges + E, compareEdges);

    int res = 0;
    for (int i = 0; i < E; i++) {
        res = mergeFirst(i, res);
    }

    cout << "The Best MST is: " << res << "\n";

    int sec_best_mst = INT_MAX;

    res = 0;
    int j;
    for (j = 0; j < present.size(); j++) {
        initialize(V);
        edge = 0;
        for (int i = 0; i < E; i++) {
            if (i == present[j])
                continue;
            res = mergeSecond(i, res);
        }

        if (edge != V - 1) {
            res = 0;
            continue;
        }

        if (sec_best_mst > res)
            sec_best_mst = res;
        res = 0;
    }

    cout << "Second Best MST is: " << (sec_best_mst != INT_MAX ? sec_best_mst : -1) << "\n";
    return 0;
}
