#include <bits/stdc++.h>

using namespace std;


int power_optimised(int a,int n) {
	int ans = 1;

	while (n > 0) {

     int lastBit = n&1;

     if(lastBit) {
     	ans = ans*a;

     }
     a = a*a;

     n = n>>1; 

	}

	return ans;

}

int main() {

   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
    
    int a,n;

    cin>>a>>n;

    cout<<power_optimised(a,n)<<endl;




	return 0;
}