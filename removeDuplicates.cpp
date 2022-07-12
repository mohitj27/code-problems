#include <bits/stdc++.h>

using namespace std; 

string removeDuplicates(string a){

  int n = a.size();

  if(n ==0 || n==1) return a;

  if(a[0] == a[1]){
  	int index = 0;
  	while(a[index] == a[0] && index < n){
  		index++;
  	}
   return a[0] + removeDuplicates(a.substr(index));
  }
  return a[0] + removeDuplicates(a.substr(1));

}


int main() {


       #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;

    cin>>s;
    cout<<removeDuplicates(s)<<endl;

	return 0;
}