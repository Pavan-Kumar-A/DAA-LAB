#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> graph) {

  int n = graph.size();
  vector<int> color(n, 0);
  
  queue<int> q;
  q.push(0); 
  color[0] = 1;
  
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    
    for(int neighbor=0; neighbor<n; neighbor++) {
      if(graph[node][neighbor] == 1) {
        if(color[node] == 1) {
          if(color[neighbor] == 0) {
            color[neighbor] = 2;
            q.push(neighbor);  
          }
          else if(color[neighbor] == 1) {
            return false; 
          }
        }
        else {
          if(color[neighbor] == 0) {
            color[neighbor] = 1;
            q.push(neighbor);
          }
          else if(color[neighbor] == 2) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main() {

  freopen("input_Q3.txt", "r", stdin);
  freopen("output_Q3.txt", "w", stdout);

  int n;
  cin >> n;
  
  vector<vector<int>> graph(n, vector<int>(n, 0));

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int x;
      cin >> x;
      graph[i][j] = !x; 
      if(i == j) graph[i][j] = 0; 
    }
  }

  if(isBipartite(graph)) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}