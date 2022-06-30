#include <bits/stdc++.h>

using namespace std;

// bool isSafe(int board[][10], int i, int j
// 	, int n) {
// 	for(int row =0; row<i; row++){
// 		if(board[row][j] == 1){
// 			return false;
// 		}
// 	}
// 	int x = i;
// 	int y = j;

// 	while (x >=0 and y>=0){
// 		if(board[x][y] == 1) {
// 			return false;
// 		}
// 		x--; 
// 		y--;
// 	}

// 		 x = i;
// 	       y = j;

// 	while (x >=0 and y<n){
// 		if(board[x][y] == 1) {
// 			return false;
// 		}
// 		x--; 
// 		y++;
// 	}
// 	return true;
// }
// bool solvedQueen(int board[][10],int i, 
// 	int n) {
// 	// Base Case
// 	if(i == n) {
      
//       for(int i = 0; i<n;i++) {
//       	for(int j=0; j< n; j ++) {
//       		if(board[i][j] == 1){
//       			cout<<" Q ";
//       		}
//       		else {
//       			cout<< " . ";
//       		}
//       	}
//       	cout<<endl;
//       }
//       cout<<endl<<endl;
//       return false;
// 	}
// 	// rec case 
// 	// Try to place queen in current row
// 	for(int j=0; j <n; j++){
//       if(isSafe(board,i,j,n)){
//       	board[i][j] = 1;
//        bool nextQueenRakhPaye = 
//        solvedQueen(board,i+1,n);
//        if(nextQueenRakhPaye) {
//        	return true;
//        }
//        board[i][j] = 0;
//       }

// 	}
//      return false;
// }
    bitset<30> col,d1,d2;

void solve(int r, int n, int &ans
	  ) {
	if(r== n) {
		ans++;
		return;
	}
	for(int c=0; c<n;c++){
		if(!col[c] and !d1[r-c + n-1]
			and !d2[r+c]){
			col[c] = d1[r-c+n-1] = 
		    d2[r+c] = 1;
		   // rec case 
		    solve(r+1,n,ans);
		    col[c] = d1[r-c+n-1] = 
		    d2[r+c] = 0;
		}
	}
}
int ans = 0,DONE;
void solveBit (int rowMask, int ld,int rd) {
	if(rowMask == DONE) {ans++; return;}
	int safe = DONE & (~(rowMask | ld | rd));
	while (safe) {
		int p = safe & (-safe);

		safe = safe - p;

		solveBit(rowMask | p,(ld |p)<<1,(rd |p) >>1);
	}
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
    DONE = ((1 <<n) - 1);
    solveBit(0,0,0);
     // cout << ans;
   int board[10][10] = {0};
   // int ans = 0;
   // solve(0,n,ans);
   cout<<ans<<endl;
   // solvedQueen(board,0,n);

   return 0 ; 
}