#include <bits/stdc++.h>


using namespace std;

class node{
 public:
 unordered_map<char,node*> children;
 int count;
 char data;
 bool terminal;
      node(char d){
        data = d;
        terminal = false;
        count = 0;        
      }

};

class Trie{
     public:
     	node * root;
      Trie(){
      	root = new node('\0');
      }

      void insert(char * word) {
        
        node *temp = root;

        for(int i = 0; word[i]!= '\0';i++){
        	char ch = word[i];
        	if(temp->children.count(ch)){
        		temp = temp->children[ch];
        		
        	}else {
        		node *n = new node(ch);
        		temp->children[ch] = n;
        		temp = n;
        	}
        	temp->count+=1;

        }
                	temp->terminal = true;

      }

      vector<string> advanceSearch(char *prefix){
             
             vector<string> autoCompWords;

             node * currentNode = root;
             int index = -1;
             for(int i = 0; prefix[i] != '\0';i++){
             	index+=1;
             	if(currentNode->children.count(prefix[i])){
             	currentNode = currentNode->children[prefix[i]];
                 } else{
                 	return autoCompWords;
                 }
             	
             }
             searchWords(currentNode,autoCompWords,prefix,index+1);

             return autoCompWords;
     
      } 
      void searchWords(node * currentNode, vector<string> & autoCompWords,
      	char*prefix,int i){
       
       if (currentNode == NULL) return;

       if(currentNode->terminal== true){
       	
       	 prefix[i] = '\0';
       	 cout<<prefix<<endl;
       	 autoCompWords.push_back(prefix);
       	 return;
       }

       for(auto k = currentNode->children.begin();
       	k!=currentNode->children.end();k++){
       	// cout<<k->first;
       	prefix[i] = k->first;
       // cout<<prefix<<endl;
       searchWords(k->second,autoCompWords,prefix,i+1);
       }

      } 
    
};

int main(){


    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

   Trie t;
  
   char words[][10] = {"cobra","dog","dove","duck"};
   
   for(int i =0;i<4;i++){
    t.insert(words[i]);
   }
   char prefix[100];
    prefix[0] = 'd';
    prefix[1] = 'o';
    
   vector<string> ans;

   ans = t.advanceSearch(prefix);

	return 0;
}