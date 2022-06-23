#include <bits/stdc++.h>

using namespace std;

void move(int n, char src, char helper , char dest){

	if (n ==0) return;


	move(n-1,src,dest,helper);

	cout<<"Shift disl"<<n << "from" <<src << "to" <<dest<<endl;

	move(n-1,helper,src,dest);
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

    move(n,'A','B','C');
     
     binary consist of only 0 and 1

  pehle col vala loop h 
  use sahi karo 
  code m
  mera code dekho idhar

  map<char,int> a[100];

  for(int i=0; i< str.len(); i++) { 
  	a[str]++;

  }
   
   for(ans: a) {

   	  cout<<ans.key<<ans.value;
   }



    for(int i = 0;  i < col ; i ++) {
    	for (int j = 0; j < row; j++) {
    		if(mat[j][i] == 1) {
    			ans = i;
    			break;

    		}
    	}
    }



	retrun 0;
}

just iterate matrix and check whether it is 1 in column then it would return answer O(n2)


