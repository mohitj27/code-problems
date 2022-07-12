#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
	if(n == 0 or n == 1){
		return n;
	}
	int ans;

	ans = fib(n-1) + fib(n-2);

	return ans;
}
int topDownFib(int n,int dp[]){

	if(n==0 or n==1) return n;

	if(dp[n]!=0) return dp[n];
	int ans = topDownFib(n-1,dp) + topDownFib(n-2,dp);

	return dp[n] = ans;
}

int bottomUpFib(int n){
    int dp[100];
     dp[1] = 1;
    for(int i=2;i<=n;i++){
    	dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}
int fibSpaceOpt(int n) {
	if(n==o or n == 1) return n;

	int a =0;
	int b = 1;
	int c;
	for(int i=2; i <=n; i++) {

		c= a +b;
		a = b;
		b = c;
	}
	return c;
}
// Min steps to one
// n-> n/3,n/2,n-1
int minStepsOne(int n,int dp[]) {
   
   // Base Case 
	if(n == 1){
		return 0;
	}
    //Lookup 
   if(dp[n]!=0){
   	return dp[n];
   }
	// rec case 

	int op1,op2,op3;
	op1 = op2 = op3 = INT_MAX;

	if(n%3 == 0) {
         op1 = minStepsOne(n/3,dp) + 1;
	} 
	if(n%2 ==0) {
		op2 = minStepsOne(n/2,dp) + 1;

	} 
	op3 = minStepsOne(n-1,dp) + 1;
   
   int ans = min(min(op1,op2),op3);

    return dp[n] = ans;

}
int minStepsBottomUp(int n){

	int dp[100] = {0};
	dp[1] = 0;
	for(int i =2; i<=n; i++){
    int op1,op2,op3;
    op1 = op2 = op3 = INT_MAX;
    if(n%3 ==0){
    	op[1] = dp[i/3];
    }
    if(n%2==0){
    	op[2] = dp[i/2];

    };
    op[3] = dp[i-1];
    
    dp[i] = min(min(op1,op2),op3);
	}
	return dp[n];


}
// top down - rec solution

int minCoins(int N,int coins[],int T,int dp[]){
   if(n == 0) return 0;
   
   if(dp[n]! = 0) return dp[n];
   int ans = INT_MAX;
    
   for(int i =0; i <T; i++) {
    if(n-coins[i]>=0) {
   	int subProb = minCoins(n-coins[i],coins,T,dp);
   	ans = min(ans,subProb + 1);
   }
   }
      return dp[n] = ans;

}
int minCoinsBottomUp(int N,int coins[],int T){
    
    int dp[100] = {0};

    for(int n = 1; n<=N; n++) {
    	dp[n] = INT_MAX;

    	for(int i =0; i <T; i++) {

    		if(n-coins[i]>=0) {
    			int subprob = dp[n-coins[i]];
    			dp[n] = min(dp[n],subprob+1);
    		}
    	}
    }	
    return dp[N];
}
// Top down approach
int maxProfitSellingBottles(int wines[],int i,
	int j,int y,int dp[][100]){
   // Base Case

	if(i>j) return 0;
    if(dp[i][j]!=0) return dp[i][j];

	int op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
	int op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);
    
    return dp[i][j] = max(op1,op2);


}
// Bottom up approach
int maxProfitSellingBottlesBU(int wines[],int y) {
   
   int dp[100][100] = {};
   int year = y;
   for(int i =0; i<n; i++){
   	dp[i][i] = year * arr[i];
   }
   for(int len = 2; len <=n; len++){
   	int srt = 0;
   	int end = n - len ;
   	while(srt <= end) {
   		int endwindow = srt + len - 1;
   		dp[srt][endwindow] = max(
   			wines[srt]*year + dp[srt+1][endwindow],
   			wines[endwindow]*year + 
   			dp[srt][endwindow-1]);
   		++srt;
   	}
   	-- year;
   }

  for(int i = 0; i <n; ++i){
  	for(int j =0; j <n; ++j){
  		cout<<setw(3)<<dp[i][j]<<" ";
  	}
  	cout<<endl;
  }
  return dp[0][n-1]
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

    cout<<fib(n);

	return 0;
}