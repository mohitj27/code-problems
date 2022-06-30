#include <bits/stdc++.h>

using namespace std;

int lastIndex(int a[], int n, int m){

	if (n == 0) return -1;

	int lIndex = lastIndex(a+1,n-1,m);

	if(lIndex == -1) {
		if(a[0] == m ) {
			return 0;
		}
		else return -1;
	}

	return lIndex + 1;
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

    for(int i =0 ; i < n ; i++) {
    	cin>>a[i];
    }

    int m; cin >> m;
     cout<<lastIndex(a,n,m);

     return 0;
}