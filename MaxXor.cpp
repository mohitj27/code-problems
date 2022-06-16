#include <bits/stdc++.h>
using namespace std;

// {5 6} 0110, 0101  tries // for fun // bit 
//manipulation for fun
// { 5^6, 5^5, 6^6} = 3 
int max_xor(int arr[] , int n) {

   int mask = 0;

   int ans = 0;

   int i,j;

   for(i = 31; i>=0; i--) {

   	mask = mask | (1<<i); // eg 0010
   	set<int> s;

   	for(j =0; j<n; j++) 
   	{
   		s.insert((arr[j] & mask));

             // either 100000 or 00000
         // 0000 0100 0010 
   	}
   	int candidate = ans | (1<<i); // 0100 | 0010
       // 0110
   	set<int> ::iterator it;
   	for(it = s.begin(); it!=s.end();it++){
   		if(s.find(*it^candidate) != s.end() ){
            // 0100
   			ans = candidate; // 0110
   			break;
   		}
   	}
   }

   return ans;

}

int main() {
    
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  
     int x,y;

	 cin>>x>>y;


    
      int n =  (y-x) + 1;
     int *a = new int[n];
     int j =0;
	 for(int i=x; i <= y; i++)    {

        a[j++] = i;
	 }

	 cout<<max_xor(a,n)<<endl;

	 return 0;
}