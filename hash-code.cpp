
//hash-code cpp

#include <iostream>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    int contributor,project;

    cin>>contributor>>project;
    
    pair<string,int> pairOfContributor[contributor];

    for(int i=0; i< contributor; i++) {
      
      cin>>pairOfContributor[i].first>>cin>>pairOfContributor[i].second;

      pair<string,int> namePlusSkill[pairOfContributor[i].second];
      for(int j=0; j< pairOfContributor[i].second; j++) {
        
        cin>>namePlusSkill[j].first>>namePlusSkill[j].second;
      }

    }
}