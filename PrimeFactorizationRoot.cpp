#include <bits/stdc++.h>

using namespace std;


void printFactors(int n) {
   
    vector<pair<int, int> > factors;
  int cnt;

	for(int i =2;i*i <=n; i++) {
    

       if(n % i == 0) {
          cnt = 0;

          while( n % i == 0) {
          	cnt++;

          	n = n/i;
          }
           factors.push_back(make_pair(i,cnt));
       }
	}
	if(n!= 1) {
		factors.push_back(make_pair(n,1));

	}

	for(auto p : factors) {

		cout<< p.first << "^" << p.second << endl;
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

    printFactors(n);









	return 0;
}