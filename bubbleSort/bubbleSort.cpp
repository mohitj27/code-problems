// As the name suggest bubble, so bubbles which are big in space comes to top of the surface so that is bubble sort

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
  void bubbleSort(int *a,int n, bool (&cmp)(int a,int b)) {
      for(int iter=0; iter< n ;iter++) {
           for(int j=0;j<(n-iter-1);j++) {
              if(cmp(a[j],a[j+1])){
                  swap(a[j],a[j+1]);
              }
           }
      }
  }

int main() {
      
     int n;
    cin>>n;
   int *a = new int[n];
    
    for(int i=0; i <n; i++) {
        cin>>a[i];
    }
    bubbleSort(a,n,cmp);
    for(int i=0; i <n; i++) {
        cout<<a[i];
    }
  
     
    return 0;
}