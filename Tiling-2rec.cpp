#include<iostream>
using namespace std;
#define mod 1000000007
int findTotalWays(int n,int m,int dp[]){
	if(n ==0) return dp[n] = 1;
	if(n<m) {
 
		return dp[n] = 1;}
	 if(dp[n]!=0) {  return dp[n];}
 
     dp[n] = (findTotalWays(n-1,m,dp)%mod + findTotalWays(n-m,m,dp)%mod)%mod;
	return dp[n];

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
	while(t--) {
		int dp[100000] = {0};
		int n,m;
		cin>>n>>m;
		cout<<findTotalWays(n,m,dp)<<endl;
	}

	return 0;


}