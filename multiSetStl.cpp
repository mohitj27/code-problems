#include <bits/stdc++.h>
using namespace std;

// MUltiSety - that can store multiple elements that have same elements
// stored in some specific order
// values cant be modified like sets
// associative container
// elements are referred by their values not by the index
// underlying data structure - BST

typedef multiset<int>::iterator It;
class person_compare{
public:
	bool operator()(pair<string,int>p1,pair<string,int> p2) {
		return p1.second< p2.second;
	}
};
int main () {

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
int arr[] = {10,20,30,30,10,10};

multiset<int> m(arr,arr+6);
m.erase(20);
cout<<m.count(10)<<"hahahahah";
for(auto x: m){
	cout<<x<<",";
}    
cout <<endl;
auto it = m.find(30);
pair<It,It> range = m.equal_range(30);

for(auto it = range.first;it!= range.second;it++){
	cout<<*it<<".";
}


// Lower Bound and upper Bound

for(auto it = m.lower_bound(10);it!=m.upper_bound(77);it++){
	cout<<*it<<"---";
}

 pair<string,int> p1 = make_pair("B",100);
 pair<string,int> p2 = make_pair("A",40);
 pair<string,int> p3 = make_pair("C",120);
 pair<string,int> p4 = make_pair("D",10);

// multiset 

// Custom Data type
 multiset<pair<string,int>, person_compare > m2;
 m2.insert(p1);
 m2.insert(p2);
 m2.insert(p3);
 m2.insert(p4);

// pair - P
 for(auto p:m2) {
 	cout<<p.first<<" - "<<p.second<<endl;
 }
return 0;
}