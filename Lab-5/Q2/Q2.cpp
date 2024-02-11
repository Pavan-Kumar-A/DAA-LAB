#include<bits/stdc++.h>
using namespace std;

bool visited[100000];

int BFS(vector<int>&moves, int n) {
  
  for(int i=0; i<n; i++) {
    visited[i] = false; 
  }

  queue<pair<int,int>> q;

  visited[0] = true;
  pair<int,int> s = {0, 0};
  q.push(s);

  pair<int,int> p;

  while(!q.empty()) {
    p = q.front();
    int k = p.first;
    
    if(k == n-1) break;

    q.pop();

    for(int dice=1; dice<=6 && k+dice<n; dice++) {
      int next = k + dice;
      if(!visited[next]) {
        pair<int,int> a;
        a.second = p.second + 1;
        
        if(moves[next] != -1) {
          a.first = moves[next];
        }
        else {
          a.first = next;
        }
      
        visited[next] = true;
        q.push(a);
      }
    }
  }

  return p.second; 
}

int main() {

  freopen("input_Q2.txt", "r", stdin);
  freopen("output_Q2.txt", "w", stdout);

  int n, ladders, snakes;
  cin >> n >> ladders >> snakes;

  vector<int> moves(n);
  for(int i=0; i<n; i++) {
    moves[i] = -1;
  }

  for(int i=0; i<ladders+snakes; i++) {
    int u, v;
    cin >> u >> v;

    moves[u-1] = v-1;
  }

  cout << BFS(moves, n) << endl;

  return 0;
}