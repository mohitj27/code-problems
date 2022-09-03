
//words[] = ["cobra","dog","dove","duck"],
// output[] = ["c","dog","dov","du"]

// Trie - prefix tree
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

  class node{
  public:
  	 char data;
  	 unordered_map<char,node*> children;
  	 int count;
  	 bool terminal;
 
     node(char d){
     	data = d;
     	terminal = false;
     	count = 0;
     }

  };

  class Trie{

    int cnt;

  public: 
  	node * root;
    Trie(){
      root = new node('\0');
      cnt = 0;
    }

    void insert(char *w){
      node * temp = root;
      for(int i=0;w[i]!='\0';i++){
        char ch = w[i];
        if(temp->children.count(ch)){
          temp = temp->children[ch];
          temp->count +=1;
        }
        else{
          node * n = new node(ch);
          temp->children[ch] = n;
          temp = n;
          temp->count += 1;
        }
      }
       temp->terminal = true;
    }
   


  };

    void printPrefixHelper(node * head, char prefix[],int i) {
     
     if(head == NULL) return;

     // if(head->count == 2 & head->terminal == true){
     // 	prefix[i] = '\0';
     // 	cout<<"-1";
     // 	return;
     // }
       // cout<<head->count;
     if(head->count ==1) {
       prefix[i] = '\0';
       cout<<prefix<<endl;

       return;
     }
       
     for(auto k = head->children.begin();k!=head->children.end();k++){
     	prefix[i] = k->first;
     	// cout<<k->first<<endl;
     	printPrefixHelper(k->second,prefix,i+1);
     }

    }
 


int main() {


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
   char prefix[26];
   printPrefixHelper(t.root,prefix,0);


	return 0;
}