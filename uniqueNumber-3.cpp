#include <bits/stdc++.h>

using namespace std;


int main() {

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  
  int preSum[64] = {0};
  int n, no; 

  cin>>n;
 
  for(int i = 0; i <n; i ++) {

  	cin>>no;

  	int j = 0 ;

  	while(no>0) {
  		int last_bit = (no&1);

  		preSum[j]+= last_bit;
  		j++;
        no = no >> 1;
  	}
  }
   int ans =0;
   int p =1;
  for(int i =0; i<64; i++) {
   ans += (preSum[i]%3)* p; 
   p = p<<1;
  }

  cout<<ans<<endl;


	return 0;
}