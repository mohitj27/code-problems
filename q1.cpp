#include <bits/stdc++.h>

using namespace std;


bool myCompare(pair<string,int> p1, pair<string,int> p2) {
     if(p1.second == p2.second) {
        return p1.first < p2.first;
     }
     return p1.second > p2.second;
}

int main() {

int minimum , n;

cin>>minimum>>n;
   vector < pair<string,int> > a(n);
     string name; int salary;
   for(int i =0 ; i < n ; i++ ) {
       cin>>name>>salary;
       a.push_back(make_pair(name,salary));
   }
   sort(a.begin(),a.end(),myCompare);
     for(int i = 0; i < n; i++){
        if(a[i].second >= minimum){
            cout<<a[i].first<<" "<<a[i].second<<endl;
        }
     }
     return 0;

}
