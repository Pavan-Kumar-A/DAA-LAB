#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

// Utility functions 
vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
  int n = A.size();
  int m = A[0].size();

  vector<vector<int>> result(n, vector<int>(m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      result[i][j] = A[i][j] + B[i][j];
    }
  }

  return result;
}


vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
  int n = A.size();
  int m = A[0].size();

  vector<vector<int>> result(n, vector<int>(m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      result[i][j] = A[i][j] - B[i][j];
    }
  }

  return result;
}

// Function for normal divide-and-conquer multiplication
vector<vector<int>> divideAndConquerMultiply(vector<vector<int>> &A, vector<vector<int>> &B){

    int n1 = A.size();
    int n2 = B.size();


    vector<vector<int>> C(n1, vector<int>(n1, 0));

    if (n1 == 1){
        C[0][0] = A[0][0] * B[0][0];
        return C;
    } 

    int v = log2(n1);

    if (pow(2, v) != n1){
        n1 = pow(2, v + 1);
    } 

    int si = n1 / 2;

    vector<vector<int>> a00(si, vector<int>(si, 0)), a01(si, vector<int>(si, 0)), a10(si, vector<int>(si, 0)), a11(si, vector<int>(si, 0));
    vector<vector<int>> b00(si, vector<int>(si, 0)), b01(si, vector<int>(si, 0)), b10(si, vector<int>(si, 0)), b11(si, vector<int>(si, 0));

    for(int i = 0; i < si; i++){
        for(int j = 0; j < si; j++){

            a00[i][j] = A[i][j];
            b00[i][j] = B[i][j];
            if (j + si < n2){
                a01[i][j] = A[i][j + si];
                b01[i][j] = B[i][j + si];
            }
            if (i + si < n2){
                a10[i][j] = A[si + i][j];
                b10[i][j] = B[si + i][j];
            }
            if (j + si < n2 && i + si < n2){
                a11[i][j] = A[i + si][j + si];
                b11[i][j] = B[i + si][j + si];
            }
        }
    }

    vector<vector<int>> c_00 = add(divideAndConquerMultiply(a00, b00), divideAndConquerMultiply(a01, b10));
    vector<vector<int>> c_01 = add(divideAndConquerMultiply(a00, b01), divideAndConquerMultiply(a01, b11));
    vector<vector<int>> c_10 = add(divideAndConquerMultiply(a10, b00), divideAndConquerMultiply(a11, b10));
    vector<vector<int>> c_11 = add(divideAndConquerMultiply(a10, b01), divideAndConquerMultiply(a11, b11));

    for(int i = 0; i < si; i++){
        for(int j = 0; j < si; j++){

            C[i][j] = c_00[i][j];

            if (j + si < n2){
                C[i][j + si] = c_01[i][j];
            }
            if (i + si < n2){
                C[si + i][j] = c_10[i][j];
            }
            if (j + si < n2 && i + si < n2){
                C[i + si][j + si] = c_11[i][j];
            }
        }
    }

    return C;
}

// Strassen's matrix multiplication
vector<vector<int>> strassenMultiplication(const vector<vector<int>> &A, const vector<vector<int>> &B){

    int n1 = A.size();
    int n2 = B.size();

    vector<vector<int>> c(n1, vector<int>(n1, 0));

    if (n1 == 1){
        c[0][0] = A[0][0] * B[0][0];
        return c;
    }

    int v = log2(n1);
    if (pow(2, v) != n1){
        n1 = pow(2, v + 1);
    } 

    int si = n1 / 2;

    vector<vector<int>> a00(si, vector<int>(si, 0)), 
                            a01(si, vector<int>(si, 0)), 
                            a10(si, vector<int>(si, 0)), 
                            a11(si, vector<int>(si, 0));
    vector<vector<int>> b00(si, vector<int>(si, 0)),
                            b01(si, vector<int>(si, 0)), 
                            b10(si, vector<int>(si, 0)), 
                            b11(si, vector<int>(si, 0));

    for (int i = 0; i < si; i++){
        for (int j = 0; j < si; j++){

            a00[i][j] = A[i][j];
            b00[i][j] = B[i][j];

            if (j + si < n2){
                a01[i][j] = A[i][j + si];
                b01[i][j] = B[i][j + si];
            }

            if (i + si < n2){
                a10[i][j] = A[si + i][j];
                b10[i][j] = B[si + i][j];
            }

            if (j + si < n2 && i + si < n2){
                a11[i][j] = A[i + si][j + si];
                b11[i][j] = B[i + si][j + si];
            }
        }
    }

    vector<vector<int>> p1 = strassenMultiplication(a00, subtract(b01, b11));
    vector<vector<int>> p2 = strassenMultiplication(add(a00, a01), b11);
    vector<vector<int>> p3 = strassenMultiplication(add(a10, a11), b00);
    vector<vector<int>> p4 = strassenMultiplication(a11, subtract(b10, b00));
    vector<vector<int>> p5 = strassenMultiplication(add(a00, a11), add(b00, b11));
    vector<vector<int>> p6 = strassenMultiplication(subtract(a01, a11), add(b10, b11));
    vector<vector<int>> p7 = strassenMultiplication(subtract(a00, a10), add(b00, b01));

    vector<vector<int>> c_00 = subtract(add(add(p5, p4), p6), p6);
    vector<vector<int>> c_01 = add(p1, p2);
    vector<vector<int>> c_10 = add(p3, p4);
    vector<vector<int>> c_11 = subtract(add(p1, p5), add(p3, p7));

    for (int i = 0; i < si; i++){
        for (int j = 0; j < si; j++){

            c[i][j] = c_00[i][j];

            if (j + si < n2){
                c[i][j + si] = c_01[i][j];
            }

            if (i + si < n2){
                c[si + i][j] = c_10[i][j];
            }

            if (j + si < n2 && i + si < n2){
                c[i + si][j + si] = c_11[i][j];
            }
        }
    }

    return c;
}


// Driver code
int main() {

    freopen("input_Q1.txt", "r", stdin);
    freopen("output_Q1.txt", "w", stdout);

  int t;
  cin >> t;

  while(t--) {

    int n; 
    cin >> n;
    
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> A[i][j];  
      }
    }
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> B[i][j];
      }  
    }
    vector<vector<int>> C(n, vector<int>(n)); 
    
     C = divideAndConquerMultiply(A, B);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << C[i][j] << " ";
      }
      cout << "\n";
    }
    
    cout << "\n";
  }
  return 0;
  
}
