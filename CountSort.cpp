#include <iostream>
#include <algorithm>

using namespace std;


void countSort(int *a, int n,int *result) {


int mx = *max_element(a,a+n);

int *count =  new int[mx];

memset(count, 0, mx);

for(int i = 0; i < n ; i ++) {
	count[a[i]]++;
}
int res=0,lop=0;

while(lop<= mx) {
 if(count[lop]> 0) {
 	// cout<<count[a[lop]]<<"dd"<<a[lop];
 	result[res] = lop;
 	res++;
 	count[lop]--;

 	 } else {
 	 	lop++;
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


    for(int i=0; i < n ; i ++) {

         cin>>a[i];

    }

    int *result = new int[n];

        countSort(a, n, result);

    for(int i=0; i < n ; i ++) {

        cout<<result[i]<<" ";

    }


	return 0;
}