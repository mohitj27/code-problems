#include <bits/stdc++.h>

using namespace std;

//unique
//ordered

int main() {

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    int arr[] = {10,20,11,9,8,9};

    int n = sizeof(arr)/sizeof(int);

    set<int> s;
    set< pair<int,int>> s2;
    
    s2.insert(make_pair(10,5));
    s2.insert(make_pair(20,5));
    s2.insert(make_pair(20,100));
    s2.insert(make_pair(5,5));
    s2.insert(make_pair(3,5));
    s2.insert(make_pair(7,5));
    
    s2.erase(s2.find(make_pair(3,5)));
     
     for(auto p: s2){
     	cout<<p.first << " ands  "<<p.second<<endl;  
     }

    for(int i =0; i<n; i++) {

    	s.insert(arr[i]);
    }

    for(set<int>::iterator it = s.begin(); it!= s.end();it++) {
    	cout<<*(it)<<endl;
    }





	return 0;
}