#include <bits/stdc++.h>

using namespace std; 

int maxSumSubArray(int *a,int n,int *result){
	if(n ==0) {
        return a[n]; }
     
     int smallAns = maxSumSubArray(a,n-1,result);

     cout<<smallAns<<endl;
     cout<<a[n]<<endl;
      *result = max(*result,max(smallAns+a[n],a[n]));
       
      
     return smallAns + a[n] > smallAns ? 
     (smallAns + a[n]):a[n];


}

int main() {

   
       #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
   int n;
   cin>>n;
   int a[n];
   int result = 0;
   for(int i=0; i <n;i++) cin>>a[i];
    cout<<maxSumSubArray(a,n-1,&result)<<endl;

    cout<<result<<endl;

	return 0;
}