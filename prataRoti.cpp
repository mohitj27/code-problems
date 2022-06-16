#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool isPossible(int A, int B, vector<long long int> &C, int curr_min) {
  
  
  int painter = 1;
   int tottime = 0;

   for(int i=0; i < C.size();i++) {
       if(tottime + C[i]>curr_min) {
           painter++;
           tottime = C[i];
           if(painter > A) return false;
       }
       else {
           tottime+= C[i];
       }


   }
 return true;


}
int paint(int A, int B, vector<long long int> &C) {

for(int i=0; i<C.size(); i++) {
      C[i] = C[i]*B;
  }
long long int end = accumulate(C.begin(),C.end(),0);
long long int start = *max_element(C.begin(),C.end());
long long int ans = INT_MAX;


while (start<= end) {

long long int mid = (start + end) >>1;

cout<<mid<<endl;
if(isPossible(A,B,C,mid)) {
 ans = min(mid,ans);
 cout<<ans<<endl;
 end = mid-1;
} else {
    start = mid+1;
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

int a,b,d;

cin>>d>>a>>b;
vector<long long int> c;

int temp;
for(int i =0;i <d; i++) {
cin>>temp;
c.push_back(temp);
}
cout<<paint(a,b,c)<<endl;

}