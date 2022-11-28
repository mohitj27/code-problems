#include <bits/stdc++.h>

using namespace std;

long long int minCoins(int n, int coins[], int T, long long int dp[]){
   if(n == 0) return 0;
   if(dp[n] != 0) return dp[n];
   

   long long int ans = INT_MAX;

   for(int i =0 ;i < T; i++) {
   	if(n - coins[i] >=0) {
   	long long int subprob = minCoins(n - coins[i],coins,T,dp);
    cout<<subprob<<endl;
   	ans = min(ans,subprob+1); }
   }

   dp[n] = ans;

   return dp[n];

}


int main() {

	 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int T; 

    cin>>T;
    int coins[T];
    long long int dp[n+1];
    for(int i =0; i < T; i ++) {
    	cin>>coins[i];
    }
    for(int i =0 ; i <= n; i++) {
    	dp[i] = 0;
    }
    cout<<minCoins(n,coins,T,dp)<<endl;
   
}