#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> a, int key) {

	int start = 0;
	int end = a.size()-1;
  int ans = -1;
	while(start<=end){
		int mid = (start+end)/2;

		if(a[mid] == key) {
           ans = mid;
           end = mid-1;
		} else if(a[mid]>key){
            end = mid-1;
		}
		else {
			start = mid+1;
		}
	}

	return ans;
}

int lastOccurence(vector<int> a,int key) {

     int start = 0;
     int end = a.size()-1;

  int ans = -1;
	while(start<=end){
		int mid = (start+end)/2;

		if(a[mid] == key) {
           ans = mid;
           start = mid+1;
		} else if(a[mid]>key){
            end = mid-1;
		}
		else {
			start = mid+1;
		}
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
   int n,key;
   cin>>n>>key;
   vector<int> a(n);
   for(int i=0;i <n;i++) cin>>a[i];

   int ans = firstOccurence(a,key);
    int lastOccurenc = lastOccurence(a,key);
    cout<<ans<<endl<<lastOccurenc;
	return 0;
}