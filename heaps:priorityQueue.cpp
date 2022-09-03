#include <bits/stdc++.h>

using namespace std;

// heap = priority Queue
// helping in finding max/min
// heap is binary tree
// it should be complete binary tree (if all levels are completely filled except
// but filling must be from left to right order)
// Heap order Property
//  max heap   ------> every parent > children
//  min heap   ------> every parent < children
// heaps as array

class Heap {
    vector<int> v;
    bool minHeap;  
    
    bool compare(int a,int b) {
    	if(minHeap) {
    		return a<b;
    	}
    	else return a>b;
    }

    public: 
    Heap(int default_size = 10,bool type = true){
    	v.reserve(default_size);
    	v.push_back(-1);
    	minHeap = true;
    }

    void push(int d){
      
      v.push_back(d);
      int idx = v.size() - 1;
      int parent = idx/2;
      while(idx > 1 and compare(v[idx],v[parent])){
      	swap(v[idx],v[parent]);
      	idx = parent;
      	parent = parent/2;
      }
    }



};

int main() {
    

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    

	return 0;
}