#include <bits/stdc++.h>

using namespace std;

void generateBrackets(char *out, int n,
	int idx, int open, int close){


	if(idx == 2*n) {
		out[idx] = '\0';

		cout<< out <<endl;
		return;
	}
 

 if (open < n) {

 	out[idx] = '{';
 	generateBrackets(out,n,idx+1,open+1,
 		close);
 }

 if (close < open) {

 	out[idx] = '}';
 	generateBrackets(out,n,idx+1,open,
 		close+1);
 }
  return;


}




int main() {

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; 

    cin>>n;
    
    char out[1000];

    int idx = 0;

    generateBrackets(out,n,idx,0,0);
   


	return 0; 
}