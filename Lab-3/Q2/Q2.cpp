#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> &a, int start, int end){
    if(end == start){
        return a[start];
    }

    int mid = start + (end - start)/2;

    int left = maxSum(a, start, mid);
    int right = maxSum(a, mid+1, end);

    int p = 0, q = 0;
    int ans = 0;

    for(int i = mid; i >= 0; i--){
        ans += a[i];
        p = max(p, ans);
    }

    ans = 0;

    for(int i = mid+1; i <= end; i++){
        ans += a[i];
        q = max(q, ans);
    }

    int total = q + p;

    return max(left, max(right, total));
}

int main(){

    freopen("input_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> c(n);

        for(int i = 0; i < n; i++){
            cin >> c[i];
        }

        cout<< "max consecutive subsequence Sum is "<< maxSum(c, 0, n-1) << endl;
    }

    return 0;
}