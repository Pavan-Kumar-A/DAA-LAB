#include <iostream>

using namespace std;
int main() {

    freopen("input_Q2.txt","w",stdout);

	int tt = rand()%100; 

	cout<< tt <<"\n"; 
	while(tt--)
	{
       int n = rand()%2345; 
       cout << n <<"\n"; 
       
       for(int i = 0; i < n; i++){
            cout<<(rand()%1000) - 325<<" ";
       } cout<<"\n";
    }
    return 0;
}