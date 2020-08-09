// Selection sort 

// In Selection sort you start finding minimum element in the array and the nput that element in the starting of the arry

#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int *a, int n) {

    for(int i=0;i<n;i++) {

      int min_index = i;
     for(int j=i;j<n;j++) {
         if(a[min_index]>a[j]){
             min_index =j;
         }
     }

    swap(a[min_index],a[i]);
    }
}

int main() {
    int n;
    cin>>n;
   int *a = new int[n];
    
    for(int i=0; i <n; i++) {
        cin>>a[i];
    }
    selectionSort(a,n);
    for(int i=0; i <n; i++) {
        cout<<a[i];
    }

    return 0;
}