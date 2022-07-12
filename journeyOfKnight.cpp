#include <bits/stdc++.h>

using namespace std;

bool IsPossible(int x1,int y1,int x2,int y2,int moveLeft) {
	if((x1 == x2) and (y1 == y2) ) {
		return true;
	}
	if(moveLeft < 0) {
		return false;
	}
	return IsPossible(x1+1,y1+2,x2,y2,moveLeft-1) or 
	IsPossible(x1+2,y1+1,x2,y2,moveLeft-1);

}

int main(){

  
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
  int t;
  cin>>t;
  while(t--){
  	int x1,y1,x2,y2;

  	cin>>x1>>y1>>x2>>y2;
  	cout<<IsPossible(x1,y1,x2,y2,100)<<endl;;
  }
   return 0;
}


// can be done based on observation 
// if knight wants to move even steps then it will take evn steps and if it wants to move odd steps then it will take odd steps
// but i didnt expect this approach 