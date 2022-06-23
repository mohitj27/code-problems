#include <bits/stdc++.h>

using namespace std;

   bool checkSorted(int *a, int n){

   	if(n == 0 or n == 1) {
   		return true;
   	}

   	if (a[0] <= a[1] and checkSorted(a+1, n-1)) { return true; } 
   
     

     return false;

   }


int main() {
    
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif


    int n;

    cin>>n;

    int a[n];

    for(int i = 0; i < n ; i ++) {
    	cin>>a[i];
    }
     if(checkSorted(a,n-1)) {
     	cout<<"true"<<endl;

     }
     else {
     	cout<<"false"<<endl;
     }

   




	return 0;
}