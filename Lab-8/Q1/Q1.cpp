#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int findRoot(int node) {
    if (parent[node] != node) {
        parent[node] = findRoot(parent[node]);
    }
    return parent[node];
}

bool merge(int u, int v) {
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    if (rootU == rootV) {
        return false;
    }
    parent[rootV] = rootU;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    vector<tuple<int, int, int>> edges;
    int totalCost = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(-w, u, v);
    }

    sort(edges.begin(), edges.end());

    for (const auto& [weight, u, v] : edges) {
        if (merge(u, v)) {
            totalCost += weight;
        }
    }

    cout << -totalCost << "\n";
    return 0;
}