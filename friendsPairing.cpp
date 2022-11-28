#include <bits/stdc++.h>

using namespace std; 

int friendsPair(int n,int dp[]){
	if(n ==1) return dp[n] = 1;

	if (n ==2) return dp[n] = 2;

	if(dp[n]!=-1) return dp[n];

	return dp[n] = friendsPair(n-1,dp) + (n-1)*friendsPair(n-2,dp);
}

int main(){
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t; 
    while(t--){
       
       int n;
       cin>>n;
       int dp[n+1];
       for(int i =0; i<=n;i ++) dp[i] = -1;
       cout<<friendsPair(n,dp)<<endl;
    }


	return 0;
}