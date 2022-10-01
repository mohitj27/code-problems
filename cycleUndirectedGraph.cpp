#include <bits/stdc++.h>


using namespace std;

class Graph {
        int V; 

        list <int> *l;
public: 
	Graph(int V) {
		this->V = V;
		l = new list<int> [V];
	  }


	  void addEdge(int x,int y, bool directed = true){
		l[x].push_back(y);
	    l[y].push_back(x);
	}
    bool cycle_helper(int node,bool *visited,int parent) {
    	visited [node] = true;

    		for(auto nbr : l[node]) {
    			if(!visited[nbr]) {
                 bool cycle_mila = cycle_helper(nbr,visited,node);
                 if (cycle_mila) return true;
    			} else if(nbr!= parent) {
                   return true;
    			}
    		}

    		return false;
    
    }

	bool contains_cycle() {

		bool *visited = new bool[V];

		for(int i=0; i < V; i++) {
			visited[i] = false;
		}
		return cycle_helper(0,visited,-1);
	}

}; 

int main() {

    
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    

   Graph g(4);

   g.addEdge(0,1);
   g.addEdge(3,2);
   g.addEdge(1,2);
   g.addEdge(0,3);

   cout<<g.contains_cycle()<<endl;

	return 0;
}