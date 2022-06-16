#include <iostream>
#include <algorithm>



using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {

	return a.second < b.second;
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
     int n;
     cin>>n;
     pair<int,int> Activity[n];
     
     for(int i=0;i<n;i++){
     	cin>>Activity[i].first;
     	cin>>Activity[i].second;
     } 

     sort(Activity,Activity+n,compare);
    
    int initial = 0;
    int second = 1;
    int ans = 1;
    while (second<n){
    	if(Activity[second].first>= Activity[initial].second){
          ans++;
          initial = second;
          second++;  
    	} else {
    		second++;
    	}
    }
    cout<<ans<<endl;
	}

	return 0;
}