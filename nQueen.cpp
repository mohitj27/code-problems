#include <bits/stdc++.h>

using namespace std;

bool isSafe(int board[][10], int i, int j
	, int n) {
	for(int row =0; row<i; row++){
		if(board[row][j] == 1){
			return false;
		}
	}
	int x = i;
	int y = j;

	while (x >=0 and y>=0){
		if(board[x][y] == 1) {
			return false;
		}
		x--; 
		y--;
	}

		 x = i;
	       y = j;

	while (x >=0 and y<n){
		if(board[x][y] == 1) {
			return false;
		}
		x--; 
		y++;
	}
	return true;
}
bool solvedQueen(int board[][10],int i, 
	int n) {
	// Base Case
	if(i == n) {
      
      for(int i = 0; i<n;i++) {
      	for(int j=0; j< n; j ++) {
      		if(board[i][j] == 1){
      			cout<<" Q ";
      		}
      		else {
      			cout<< " . ";
      		}
      	}
      	cout<<endl;
      }
      cout<<endl<<endl;
      return false;
	}
	// rec case 
	// Try to place queen in current row
	for(int j=0; j <n; j++){
      if(isSafe(board,i,j,n)){
      	board[i][j] = 1;
       bool nextQueenRakhPaye = 
       solvedQueen(board,i+1,n);
       if(nextQueenRakhPaye) {
       	return true;
       }
       board[i][j] = 0;
      }

	}
     return false;
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
   int board[10][10] = {0};
   
   solvedQueen(board,0,n);

   return 0 ; 
}