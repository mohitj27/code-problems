#include <iostream>
#include <algorithm>

using namespace std;

int RotatedSorted(int a[],int key,int n){

	int end = n - 1;
    int start = 0;

    while(start<=end) {
        int mid = (start + end)/2;
    	if(a[mid] == key) {return mid;}
    	else if (a[mid] >= a[start]) {
    		if(a[start]<=key and key<=a[mid]) {
                  end = mid - 1;
    		}
    		else {
    			start = mid + 1 ;
    		}
    	} else {
    		if(key>= a[mid] and key<=a[end]) {
    			start = mid + 1;
    		} else {
    			end = mid - 1;
    		}
    	}
    } 
    return -1;

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
     for(int i = 0; i<n;i++ ) {
       cin>>a[i];
     }
     int key;
     cin>>key;
     cout<<RotatedSorted(a,key,n)<<endl;

	return 0;
}