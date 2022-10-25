#include <bits/stdc++.h>

using namespace std; 

class Graph {
	int V;
	list <pair<int, int>> l;
public:
	Graph(int V){
		this->V = V;
	}
	void addEdge(int x,int y){
     l.push_back(make_pair(x,y));
	}
    
    int findSet(int i, int parent[]) {
    	if(parent[i] == -1) return i;

    	return findSet(parent[i],parent);
    }

    int unionSet(int x, int y,int parent[]) {
       int s1 = findSet(x);
       int s2 = findSet
    }

	bool containsCycle(){


	}
};




int main() {




	return 0;
}