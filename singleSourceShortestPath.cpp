#include <bits/stdc++.h>

using namespace std;

class Graph {

	map<int , list <int> > l;


public:
	void addEdge(int x,int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
    
    void bfs( int src) {
    	map<int, int> dist;

    	queue<int> q; 


    	for(auto node_pair : l) {
            int node = node_pair.first;
            dist[node] = INT_MAX;
    	}
    	
    	q.push(src);
    	dist[src] = 0;

    	while(!q.empty()){
    		int node = q.front();
    		q.pop();
    		cout<<node << " ";

    		for(int nbr : l[node]) {
    			if(dist[nbr] == INT_MAX) {
    				q.push(nbr);
    				dist[nbr] = dist[node]+1;
    			}
    		}
    	}

    	for(auto node_pair:l){
    		int node = node_pair.first;
    		int d = dist[node];

    		cout<< "Node "<< node << "Dist from src" << d << endl;
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
   g.addEdge(3,4);
   g.addEdge(4,5);

   g.bfs(0);





	return 0;
}