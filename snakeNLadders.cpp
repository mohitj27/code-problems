#include <bits/stdc++.h>

using namespace std;

class Graph {
    
    map<int , list <int> > l;

public:

    void addEdge(int x,int y){

    	l[x].push_back(y);
    }

    int bfs(int src,int dest){

    	map<int,int> dist;

       map<int,int> parent;


    	queue<int> q;
   
    	for(auto p : l){
    		int node = p.first;

    		dist[node] = INT_MAX;
    	}
    	q.push(src);
    	dist[src] = 0;
        parent[src] = src;     
    	while(!q.empty()){
    		int node = q.front();

    		q.pop();

    		for(auto nbr: l[node]){
    			if(dist[nbr] == INT_MAX){
    				q.push(nbr);
    				dist[nbr] = dist[node]+1;
    				parent[nbr] = node;
    			}
    		}
    	}
         
         int temp = dest;

         while(temp!= src){
         	cout<<temp<< " <<--";
         	temp = parent[temp];
         }
        cout<<src<<endl;
    	return dist[dest];
    }


};


int main() {
   
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    // input

    int board[50] = {0};

    // Sankes // Ladders

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    // Add Edges to the Grapg

    Graph g; 

    for(int i=0;i<=36;i++){
    	for(int dice =1; dice<=6;dice++) {
    		int j = i + dice;
    		j+=board[j];

    		if(j<=36) g.addEdge(i,j);
    	}
    }
    g.addEdge(36,36);

   cout<<g.bfs(0,36)<<endl;


	return 0;
}