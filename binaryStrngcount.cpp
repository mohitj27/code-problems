#include <bits/stdc++.h>

using namespace std;

int countBinaryString(int n,int dp[]){
	if(n == 0) return dp[n] =1;
	if(n == 1) return dp[n] = 2;

	if(dp[n]!= 0 ) return dp[n];

	return dp[n] = countBinaryString(n-1,dp) + countBinaryString(n-2,dp);
}
int main() {
    

    
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
   int * dp = new int[n]();
   	cout<<countBinaryString(n,dp)<<endl;
   }    

	return 0;
}