// Given a Number N, find number of set bits in binary rep. of it 
// N = 13, Binary = 1101, ans = 3

#include <iostream>

using namespace std;

// First  Method
int setCountBits(int n) {
int ans = 0; 
while(n>0) {
 ans += (n&1);
 n = n>>1;

}

return ans;
}


// Second Method 

int countBitssFast(int n) {

   int ans = 0;

   while(n>0) {

   	n = n & (n-1);
   	ans++;
   }
   return ans;

}

// Third method - Inbuilt Method

int main() {


  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
	int n;

	cin>>n;

	cout<<__builtin_popcount(13)<<endl;
}