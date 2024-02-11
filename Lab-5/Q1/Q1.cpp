#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& matrix, int i, int j, int rows, int cols){

  if(i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] == 0){
    return 0;
  }

  matrix[i][j] = 0;
  int size = 1;

  size += dfs(matrix, i+1, j, rows, cols);
  size += dfs(matrix, i-1, j, rows, cols);
  size += dfs(matrix, i, j+1, rows, cols);
  size += dfs(matrix, i, j-1, rows, cols);
  size += dfs(matrix, i+1, j+1, rows, cols);
  size += dfs(matrix, i-1, j-1, rows, cols);
  size += dfs(matrix, i+1, j-1, rows, cols);
  size += dfs(matrix, i-1, j+1, rows, cols);

  return size;
}

int findMaxRegion(vector<vector<int>>& matrix, int rows, int cols){
  
  int maxRegion = 0;

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(matrix[i][j] == 1){
        maxRegion = max(maxRegion, dfs(matrix, i, j, rows, cols));
      }
    }
  }

  return maxRegion;
}

int main(){

  freopen("input_Q1.txt", "r", stdin);
  freopen("output_Q1.txt", "w", stdout);

  int n;
  cin >> n;

  vector<vector<int>> matrix(n+2, vector<int>(n+2, 0));

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> matrix[i][j]; 
    }
  }

  cout <<"Largest region is : "<< findMaxRegion(matrix, n+2, n+2) << endl;

  return 0;
}