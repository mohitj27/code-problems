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
	void dfs() {
		map<int, bool > visited;

		for(auto p:l){
			int node = p.first;
			visited[node] = false;
		}
         int cnt = 0;

      for(auto p: l){
         int node = p.first;
         if(!visited[node]){
           cout<<"Component "<<cnt<< " -->";
           dfs_helper(node,visited);
           cnt++;
         }
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
    
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);

    
    g.dfs();

	return 0;
}