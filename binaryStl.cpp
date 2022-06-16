#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {10,43,43,43,43,54,75,86};

    int n = sizeof(arr)/sizeof(int);

    int key;

    cin>>key;

    bool present = binary_search(arr,arr+n, key);


    if(present) {

    	cout<<"present"<<endl;

    } else {
    	cout<<"not present";
    }

    int* it  = lower_bound(arr,arr+n,key);
      cout<<"lowr bound" << (it-arr) <<endl;


      // upper bound - lower bpiond gives the frequency of the elements availabe in the sorted array

    int* uit = upper_bound(arr,arr+n,key);
    
    cout<<"uppr bound"<<(uit-arr)<<endl;  

	return 0;
}