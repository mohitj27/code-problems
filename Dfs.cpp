#include <bits/stdc++.h>

using namespace std;

class Graph {
   
   map< int, list<int> > l;

public:
	void addEdge(int x,int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

    void dfs_helper(int src, map<int,bool> &visited) {
    	cout<<src<<" ";
       visited[src] = true;
      for(int nbr : l[src]){
      	if(!visited[nbr]) {
      		dfs_helper(nbr,visited);
      	}
      }

    }
	void dfs(int src) {
		map<int, bool > visited;

		for(auto p:l){
			int node = p.first;
			visited[node] = false;
		}
		dfs_helper(src,visited);
	}
};

int main() {


   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);
    
    g.dfs(0);

	return 0;
}