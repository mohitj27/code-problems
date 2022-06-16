#include <iostream>

using namespace std;

float findsqrt(int n,int p) {

  int start = 0;

  int end = n/2;

  float ans = -1;
  while(start<= end) {
    int mid = (start + end)>>1;

    if(mid*mid == n) {
        return mid;
        
    } else if(mid*mid < n){
       ans = mid;
       start = mid+1;

    } else {
    	end = mid- 1;
    }



  }

  float inc = .1;

  for(int i = 0;i <p;i++) {

  	while(ans*ans<=n){
  		ans += inc;
  	}
  	ans = ans - inc;
  	inc = inc/10;
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

    int n;
    int p;			
    cin>>n>>p;

    cout<<findsqrt(n,p)<<endl;



	return 0;
}