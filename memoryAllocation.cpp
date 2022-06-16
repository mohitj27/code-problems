#include <iostream>

using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif


     int b[100];

     cout<<sizeof(b)<<endl;
      int n;

      cin>>n;
     int *a = new int[n];

     cout<<sizeof(a)<<endl;

     for(int i=0;i<n;i++){

     	cin>>a[i];

     	cout<<a[i]<<" ";
     }

     delete [] a;


     int **arr;
     int r,c;
     cin>>r>>c;

     arr = new int*[r];

     for(int i=0; i <r;i++){

     	arr[i] = new int[c];
     }
  int val =1;
     for(int i=0;i<r;i++) {
     for(int j=0;j<c;j++){	arr[i][j] = val;

     	val++;
     	cout<<arr[i][j];
     }
     }
	return 0;

}