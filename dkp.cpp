#include <bits/stdc++.h>

using namespace std;

class Graph {

	int V; 
	map< int , list< pair< int,int> > > l;

public:
	Graph(int V) {
       
      this->V = V;
	}

	void addEdge(int x, int y,int dist) {
		l[x].push_back(make_pair(y,dist));
		l[y].push_back(make_pair(x,dist));
	}
    
    void dkp(int src) {
    	map < int, int > dist; 

    	for(int i = 1; i <= V; i++) {
    		dist[i] =  INT_MAX;
    	}

    	dist[src] = 0;

    	set<pair<int,int>> s;

    	s.insert(make_pair(0,src));

    	while(!s.empty()){
    		auto p = *(s.begin());

    		int node = p.second;
    		int distance = p.first;

    		s.erase(s.begin());
            
            for(auto nodepair : l[node]) {
            	if(nodepair.second + distance < dist[nodepair.first]  ) {
                  auto f = s.find(make_pair(dist[nodepair.first],nodepair.first));
                  if(f!= s.end()) s.erase(f);
                  dist[nodepair.first] = nodepair.second + distance;
                   	s.insert(make_pair(dist[nodepair.first],nodepair.first));

                   	}
            }


    	}

    	for(auto distance : dist) {
    		if(distance.first != src)
    		cout<<distance.second << " "; 
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
    
    int t;
    cin>>t;
    while(t--) {
    	int e,v;
    	cin>>v>>e;

    	Graph g(v);
        int x, y, diist;
    	for(int i =0; i <e; i ++) {
         cin>> x >> y >> diist;

         g.addEdge(x,y,diist);
         cout << endl;
    	}
    	int src;
    	cin>>src;
    	g.dkp(src);
    }




	return 0;
}