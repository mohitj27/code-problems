#include <bits/stdc++.h>
#include <string>

using namespace std;
void permute(char *in, int i, set<string> &s) {
	// base case
     
     if(in[i] == '\0') {
     	
     	// cout<<in<<endl;
     	string gd(in);
     	s.insert(gd);
     	return;

     } 

     for (int j = i; in[j]!= '\0';j++){
        
        swap(in[i],in[j]);
        permute(in,i+1,s);

        // Backtracking - to restore the 
        // original array

        swap(in[i],in[j]);
     }



	
}

int main() {
     
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    set<string> s;
	char in[100]; 
	cin >> in;
	
   permute(in,0,s);

   for(auto str: s){ cout<<str<<",";}
	return 0;
}