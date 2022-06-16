#include <iostream>
#include <algorithm>
using namespace std;


bool cowsKaHoPayega(int *stalls,int stall, int noOfCows,int minDistance) {

	int temp = stalls[0];
    int count = 1;
	for(int i = 1; i < stall; i++) {

		if(stalls[i]- temp >= minDistance) {
          count++;
          temp = stalls[i];
          if(count == noOfCows) return true;
		}
	}

	return false;
}

int findMinimumDistance(int *stalls,int stall, int noOfCows) {

	sort(stalls,stalls+stall);

	int start = 0;
	int end = stalls[stall-1] - stalls[0];
    int cowsKaMinimumDistance = 0;
	while(start<=end) {
		int mid = (start+end)>>1;
    if(cowsKaHoPayega(stalls,stall,noOfCows,mid)) {
    	cowsKaMinimumDistance = mid;
    	start = mid+1;
    } else {
    	end = mid - 1;
    }

	}

	return cowsKaMinimumDistance;
}

int main() {

        #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
int t;

cin>>t;
while(t--) {

long long int stall, noOfCows;

cin>>stall>>noOfCows;

int *stalls = new int[stall];

for(int i=0; i <stall;i++) {
	cin>>stalls[i];
}

cout<<findMinimumDistance(stalls,stall,noOfCows)<<endl;





}



}