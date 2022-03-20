#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int *a = new int[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		int ans = INT_MIN;
		int maxSumSoFar = 0;

		for(int i=0; i <n;i++) {
			maxSumSoFar += a[i];
            if(maxSumSoFar<0){
				maxSumSoFar = 0;
			}
			if(maxSumSoFar>ans ){
				ans = maxSumSoFar;
			}
         
		}
       cout<<ans<<endl;
	}
	return 0;
}