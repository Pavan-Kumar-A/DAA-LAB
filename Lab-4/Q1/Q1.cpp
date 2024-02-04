#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &arr){
    int n = arr.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){            
           if(arr[i] > arr[j]){
                ans++;
            }
        }
    }

    return ans;
}

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> a; 
    int left = low;     
    int right = mid + 1; 

    int inv = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            a.push_back(arr[left]);
            left++;
        }
        else {
            a.push_back(arr[right]);
            inv += (mid - left + 1);
            right++;
        }
    }


    while (left <= mid) {
        a.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        a.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = a[i - low];
    }

    return inv;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int inv = 0;
    if (low >= high) return inv;
    int mid = (low + high) / 2 ;
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid + 1, high);
    inv += merge(arr, low, mid, high); 
    return inv;
}

int inversionCount(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);
}

int main(){
    freopen("input_Q1.txt", "r", stdin);
    freopen("output_Q1.txt", "w", stdout);


        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << "Using Brute Force method number of inversion are : "<< brute_force(arr) << endl;
        cout << "Using Divide and Conquer stratergy(similar to merge sort) we get the number of inversion as : " << inversionCount(arr, n) << endl;

return 0;
}