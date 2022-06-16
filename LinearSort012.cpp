#include <iostream>
#include <algorithm>

using namespace std;



void sortLinear(int *a, int n) {

 int low = 0;

 int mid = 0;

 int high = n-1;


 while ( mid <= high )  {

   if(a[mid] ==0) {
   	swap(a[low],a[mid]);
   	low++;mid++;
   } else if (a[mid] == 1) {

   	mid++;
   } else {

   	    swap(a[mid],a[high]);
   	    high--;
   }
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

  int *a = new int[n];

  for (int i =0; i< n ; i ++) {

  	cin>>a[i];
  }

   sortLinear(a,n);
   for (int j =0; j < n; j ++) {

	cout<<a[j]<<endl;
   }

return 0;

}