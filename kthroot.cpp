// will fix this later , not working for larger inputs ryt now
#include <iostream>
#include <algorithm>

using namespace std;
int isRoot(long long int mid, long long int root) {
   long long int result = 1;
   for (int i=0; i < root; i++ ) {
     result = result * mid;
   }

   return result;
}

int findNthRoot(long long int number,long long int root,long long int precision ) {

long long int start = 0; 
long long int end = number / root; 
long long int  ans = -1;
while (start <= end) {
long long int mid = (start + end) / 2; 

   // cout<<mid<<endl;
 if(isRoot(mid,root) == number) {
   
   return mid; 

 } else if(isRoot(mid,root) < number ) {
    ans = mid; 
    start = mid+1;
 } else {
   end = mid-1;
 }

}
cout<<ans;
return ans;

}


int main() {
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
   #endif

    int t;

    cin>>t;

    while(t--) {

       double number, root, precision;

       cin>>number>>root>>precision;
       
       cout<<findNthRoot(number,root,precision)<<endl;


    }

   return 0;

}
