#include <bits/stdc++.h>
using namespace std;

int Graph[18][18][2];
long long memotable[1 << 18][18][2];

long long getminCost(int n, int m, int mask, int prev, int col)
{
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if (memotable[mask][prev][col == 1] != 0) {
        return memotable[mask][prev][col == 1];
    }

    long long ans = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (Graph[prev][i][j] && !(mask & (1 << i)) && (j != col)) {
                long long z = Graph[prev][i][j] + getminCost(n, m, mask | (1 << i), i, j);
                ans = min(z, ans);
            }
        }
    }

    return memotable[mask][prev][col == 1] = ans;
}

void buildGraph(vector<pair<pair<int, int>, pair<int, char>>> &vp, int m)
{
    for (int i = 0; i < m; i++)
    {
        int a = vp[i].first.first - 1;
        int b = vp[i].first.second - 1;
        int cost = vp[i].second.first;
        char color = vp[i].second.second;
        Graph[a][b][color == 'W'] = cost;
        Graph[b][a][color == 'W'] = cost;
    }
}

int Cost(int n, int m)
{
    long long res = 1e9;
    for (int i = 0; i < n; i++)
    {
        res = min(res, getminCost(n, m, 1 << i, i, 2));
    }
    return res != 1e9 ? res : -1;
}

int main()
{
    freopen("input_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout); 

    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, pair<int, char>>> G(m);
    for (int i = 0; i < m; i++)
    {
        cin >> G[i].first.first >> G[i].first.second >> G[i].second.first >> G[i].second.second;
    }

    buildGraph(G, m);
    cout << Cost(n, m) << '\n';
    return 0;
}
