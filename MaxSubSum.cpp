#include <bits/stdc++.h>

using namespace std;

// bottom up approach
int maxSum(int a[], int n){

	int dp[100] = {0};

	dp[0] = a[0]>0 ?a[0]:0;
    int max_so_far = dp[0];
	for(int i = 1; i <n;i++) {
		dp[i] = dp[i-1] + a[i];
		if(dp[i]<0) dp[i] = 0;
	
	max_so_far = max(dp[i],max_so_far);
    }
   return max_so_far;
}
// topDown approach - HOMEWORK

int main() {

int n;
cin>>n;
int a[n];

for(int i =0 ; i <n; i++) cin>>a[i];

	cout<<maxSum(a,n)<<endl;

return 0;

}