#include <iostream>

using namespace std;


// Replace bits in N by M

// You are given two 32- bit numbers, N and M two bit positions, i and j. 
// Write a method to set all bits between i and j in N equal to M 
// (e.g., M becomes a substring of N located at i and starting at j).

// EXAMPLE:
// Input: N = 10000000000,
// M = 10101, i = 2, j = 6

// Output: N = 10001010100

// for this we have to first cleard the range of bits from range i to j
// and then or with m left shift i. 

int clearRangeItoJ(int n, int i, int j) {

	int ones = (~0);
	int a = ones<<(j+1);
	int b = (1<<i) - 1;

	int mask = a|b;

	int ans = n&mask;

	return ans;
}

int replaceBits(int n, int m, int i, int j) {
	int n_ = clearRangeItoJ(n,i,j);

	int ans = n_ | (m << i);

	return ans;
}

int main() {

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  
    int n = 15;

    int i = 1, j = 4;

    int m = 5;

    int ans = replaceBits(n,m,i,j);
   
   cout<<ans<<endl;

   return 0;
}