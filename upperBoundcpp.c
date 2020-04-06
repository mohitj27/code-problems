#include <bits/stdc++.h>

using namespace std;


int main() {

   int n;

   cin>>n;

   int *a = new int[n];

   for(int i = 0; i < n; i++) {

    cin>>a[i];

   }
   int *result = new int[n];
   sort(a,a+n);

   for(int i = 0; i < n; i++) {

   result[i] = upper_bound(a,a+n,a[i]);
   }
   for(int i =0; i <n ; i++) {
    cout<<a[result[i]]<<" ";
   }
    return 0;


}
