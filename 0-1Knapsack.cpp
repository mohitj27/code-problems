#include <bits/stdc++.h>

using namespace std;


int profit(int N, int C, int *wt, 
	int *prices){

	if(N == 0 || C == 0) {
		return 0;
	}

	int includeItem, excludeItem;
	int ans = 0; 
	includeItem = excludeItem = INT_MIN;
    if(wt[N-1] <=C) {
	includeItem = prices[N-1] + profit(N-1,
		C-wt[N-1],wt,prices);
      }
	excludeItem = profit(N-1, C,wt,prices);

	return max(includeItem,excludeItem);
}


int main() {

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    
    int weights[] = {1,2,3,5};

    int prices[] = {40,20,30,100};

    int N = 4;
    int C = 7;
    cout<<profit(N,C,weights,prices)<<endl;
	return 0;
}