#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
    
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
      set<int> a;
    for(int i=0; i <n; i++) {
       int t;
       cin>>t;
       a.insert(t);
    }

    for(int i=1;i<=n+1; i++){
    	if(a.find(i)==a.end()){
    		cout<<i;
    		break;
    	}
    }
	 
}