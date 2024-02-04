#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int h) {
  int high = arr[h];
  int x = l;
  for (int i=l;i<h;i++) {
    if (arr[i] < high) {   // If arr[i] is less than high, then swap arr[x] with arr[i]
      swap(arr[x], arr[i]);
      x++;
    }
  }
  swap(arr[x], arr[h]);  //swap arr[x] with arr[h]
  return x;
}
int KthLargestElement(vector<int> arr,int n,int k){
    if (n == 1) {
    return arr[0];
  }
  int l = 0;
  int h = n - 1;
  int target = n-k;
  while (l <= h) {
    int pivot = partition(arr, l, h); 
    if (pivot < target) {        
      l = pivot + 1;
    }
     else if (pivot > target) {  
      h = pivot - 1;
    }
     else {            
      return arr[pivot];
    }
  }
    return -1;
}

int pqMethod(vector<int>&arr,int k){
        priority_queue<int> pq(arr.begin(), arr.end());
        for(int i=0; i<k-1; i++)
            pq.pop();
            return pq.top();
}

int main() {
    freopen("input_Q3.txt", "r", stdin);
    freopen("output_Q3.txt", "w", stdout);
  int n,k;
  cin>>n>>k;
  vector<int> arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }

  cout << "K'th largest element is(using Quick Select) " << KthLargestElement(arr,n, k)<<endl;
  cout << "K'th largest element is(Using Priority Queue) " << pqMethod(arr, k);

  return 0;
}