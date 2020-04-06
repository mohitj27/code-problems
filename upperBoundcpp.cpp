#include <bits/stdc++.h>

using namespace std;


int main() {

   int n;

   cin>>n;

   int a[n];

   for(int i = 0; i < n; i++) {

    cin>>a[i];

   }
   int *result = new int[n];
   sort(a,a+n);

   for(int i = 0; i < n; i++) {

   result[i] = upper_bound(a,a+n,a[i]) - a;
   }
   int k = sizeof(a)/sizeof(int);
   for(int i =0; i <n ; i++) {
        if(a[result[i]] == 0 || result[i] == k   ) {
            cout<<"-1"<<" ";
        } else {
            cout<<result[i]<<endl;
    cout<<a[result[i]]<<" ";
   }
   }
    return 0;


}
