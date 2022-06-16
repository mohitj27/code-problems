#include <bits/stdc++.h>

using namespace std;

int main() {
   
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  

   int t;
   
   cin>>t;
   while(t--){
    int n;

    cin>>n;

    cout<<__builtin_popcount(n)<<endl;


   }



	return 0;
}
