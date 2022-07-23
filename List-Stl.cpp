#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
   
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    list<int> l1{1,2,3,4,5,7,10};

    list<string> l2{"mohit","kanika","jeevan"};

    l2.push_back("pineapple");

    l2.sort();
    l2.reverse(); 
     l2.push_back("dipit");
     l2.push_back("apple");
     

     for(string s:l2){
    	cout<<s<<"-->";
    }
    // remove all the occurrences
    l2.remove("apple"); 
    auto it = l2.begin();
    it++;
    it++;
    l2.erase(it);
    l2.insert(it,"dfgd");
  return 0;

}