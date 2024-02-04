#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
    freopen("input_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    
    int m,n;
    cin>>m>>n;
    vector<int> a(m),b(n);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int>res(m+n);
    int i=0;
    int j=0;
    int k=0;
    while(k<=(m+n)/2&&i<m&&j<n){
        if(a[i]<=b[j]){
            res[k++]=a[i++];
        }
        else {
            res[k++]=b[j++];
        }
    }
    if(k<=(m+n)/2){
    for(;j<n;j++){
        res[k++]=b[j];
    }
    for(;i<m;i++){
        res[k++]=a[i];
    }

    }

    if((m+n)%2){
        cout<<"The median element is  :"<<res[(m+n)/2]<<endl;

        cout<<float(res[(m+n)/2]);
    }
    else{
        cout<<"The median elements are : "<<res[(m+n)/2-1]<< " and "<<res[(m+n)/2]<<endl;
        cout<<"Median is "<<float((res[(m+n)/2-1]+res[(m+n)/2]))/2;      
    }

}