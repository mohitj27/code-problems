#include <iostream>

using namespace std;

int CountStrings(int n,int dp[][2]){
      
   if(n == 0) return 1;

   if(n == 1) return 2;

   return CountStrings(n-1) + CountStrings(n-2);
   


}

int main() {


    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

	int n; 

	cin >>n ; 
	int dp[n+1][2]={};
    cout<<CountStrings(n,dp);

    return 0;

}