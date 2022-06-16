#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(string a , string b) {

string r = a.substr(0,b.length());

transform(r.begin(),r.end(),r.begin(),::tolower);

if(r==b) {
	return a>b;
}
r = b.substr(0,a.length());
transform(r.begin(),r.end(),r.begin(),::tolower);

if(r==a) {
	return b>a;
}
else {
	return a<b;
}



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

   vector<string> v; 
   cin.get();
   string w;
   
   for(int i=0; i <n ; i ++) {
   	 getline(cin,w);
   	 v.push_back(w);

   }
   
     sort(v.begin(), v.end(), compare);

     for(int i =0; i < n ; i++) {
     	cout<<v[i]<<"\n";
     }

	return 0;
}