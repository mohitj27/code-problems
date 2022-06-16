#include <iostream>

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

while(t--) {

  int a , b;

  cin >> a >> b;
  int ans = 0;
  for(int i = a ; i <= b ; i ++) {
  
      ans +=  __builtin_popcount(i);
  
  }


   cout<<ans<<endl;


}



return 0;
}