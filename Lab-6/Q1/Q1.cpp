#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

vector<int> topologicalSort(vector<vector<int> >& adj,    int V)
{
    vector<int> indeg(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indeg[it]++;
        }
    }
 
    queue<int> tsQ;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) {
            tsQ.push(i);
        }
    }
    vector<int> res;
    while (!tsQ.empty()) {
        int v = tsQ.front();
        tsQ.pop();
        res.push_back(v);
       
        for (auto &it : adj[v]) {
            indeg[it]--;
            if (indeg[it] == 0)
                tsQ.push(it);
        }
    }
 
    return res;
}
int main(){
    ios::sync_with_stdio(0);
     freopen("input_Q1.txt", "r", stdin);
    freopen("output_Q1.txt", "w", stdout);
    cin.tie(NULL);
 
   
    int V,E;
        cin >> V >> E;
        vector<vector<int> > adj(V);

        for(int i=0; i<E; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }

  
    vector<int> result = topologicalSort(adj, V);
    for (auto i : result) {
        cout << i << " ";
    }   
    cout<<endl; 
    }
