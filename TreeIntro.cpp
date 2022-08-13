#include <bits/stdc++.h>

using namespace std;

class node {

public:
	int data;
	node*left;
	node*right;

	node (int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {

	int d;
	cin>>d;
	if(d == -1) return NULL;

	node * root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
void print(node*root){
	if(root == NULL) return;

	cout<<root->data<<" ";
	print(root->left);
	print(root->right);

}
void printIn(node*root){
	if(root == NULL) return;
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);

} 
void printPost(node*root){
	if(root == NULL) return;
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";

} 
int height(node *root){
	if(root == NULL) return 0;

	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls,rs) + 1; 
}

void printKthLevel(node*root,int k) {
	if(root == NULL) return;

	if(k==1) {
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
	return;
}

void printAllLevels(node *root){
	int H = height(root);

	for(int i=1;i<=H; i++) {
		printKthLevel(root,i);
		cout<<endl;
	}
}

void bfs(node *root){

	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* f = q.front();
		cout<<f->data<<",";
		q.pop();
		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f->right);
		}
	}
	return;
}

void bfs2(node *root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
	   if(f==NULL){ cout<<endl;
	   	q.pop();
	   	if(!q.empty()) q.push(NULL);}
	   	else {
			cout<<f->data<<",";
			q.pop();
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}	
	}
	return;
}
int diameter(node*root) {
	if(root==NULL) return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1,max(op2,op3));
}

class Pair{
public:
	int height;
	int diameter;

};
Pair fastDiameter(node*root){
	Pair p;

	if(root == NULL) {
		p.diameter = p.height = 0;
		return p;

	}

	Pair left = fastDiameter(root->left);

	Pair right = fastDiameter(root->right);

	p.height = max(left.height,right.height) + 1;

	p.diameter = max(left.height+ right.height,max(left.diameter,
		right.diameter));

	return p;
}
 
 int replaceSum(node *root){
 	if(root == NULL){
 		return 0;
 	}
 	if(root->left == NULL && root->right == NULL){
 		return root->data;
 	}
 	int leftSum = replaceSum(root->left);
 	int rightSum = replaceSum(root->right);
 	int temp = root->data;

 	root->data = leftSum + rightSum;

 	return temp + root->data;

 }
    // Height balanced tree , at every node of the tree
  // | h1 - h2 | <=1 height of order of log(n)
  
  class HBpair{
  public:
  	 int height;
  	 bool balance;
  };

 HBpair isHeightBalance(node *root) {
   HBpair p;
   if(root == NULL){
   	p.height = 0 ;
   	p.balance = true;
   	return p;
   }
   HBpair left = isHeightBalance(root->left);
   HBpair right = isHeightBalance(root->right);
  p.balance = false;
   if(abs(left.height - right.height)<=1 and left.balance 
   	 and right.balance) {
   	p.height = max(left.height,right.height) + 1;
   p.balance = true;
   }
   return p;


 }

 node * buildTreeFromArray(int *a,int s,int e) {
 	if(s>e) {
 		return NULL;
 	}
 	int mid = (s+e) / 2;

 	node* root = new node(a[mid]);

 	root->left = buildTreeFromArray(a,s,mid-1);
 	root->right = buildTreeFromArray(a,mid+1,e);

 	return root;
 }
 // preorder + inorder - 1 unique tree
 // postorder + inorder - 1 uinque tree 

node* createTreeFromTrav(int *in, int *pre,int s,int e){
	static int i =0;

	if(s>e){
		return NULL;
	}
	node *root = new node(pre[i]);

	int index = -1;
	for(int j = s; s<=e; j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = createTreeFromTrav(in,pre,s,index-1);
	root->right = createTreeFromTrav(in,pre,index+1,e);

	return root;

}
node *createTreeFromTravPos(int *in,int *pos,int s,int e){
	static int i = e;

	if(s>e) return NULL;

	node* root = new node(pos[i]);
	int index = -1;

	for(int j = s; j<=e; j++){
		if(in[j] == pos[i]){
			index = j;
			break;
		}
	}
	i--;
	root->right = createTreeFromTravPos(in,pos,index+1,e);

	root->left = createTreeFromTravPos(in,pos,s,index -1);

	return root;
}

  void printRightView(node *root,int level,
  	int &maxlevel) {
    
    if(root == NULL)
    	return;

    if(maxlevel<level) {
    	cout<< root->data << " ";

    	maxlevel = level;
    }
    // right
    printRightView(root->right,level+1,maxlevel);

    //left

    printRightView(root->left, level + 1 , maxlevel);






  }

int main() {

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    // node * tree = buildTree();

    // print(tree);
    // int a[] = {1,2,3,4,5,6,7};
    // int n = 7;
    
    // node *root = buildTreeFromArray(a,0,n-1);
    // bfs2(root);

    // int in[] = {3,2,8,4,1,6,7,5};
    // int pre[] = {1,2,3,4,8,5,6,7};
     
    // int n = sizeof(in)/sizeof(int);

    // node *root = createTreeFromTrav(in,pre,0,n-1);
    // bfs2(root);

    int ind[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1}; 
    int k = sizeof(ind)/sizeof(int);

    node *root = createTreeFromTravPos(ind,post,0,k-1);
    bfs2(root);
    return 0;
}





{"house", "cat", "hope", "hair"}

"ho" -> "house", "hope"
"cat" -> "cat"
"h" -> "house", "hope", "hair"
  
       
       struct trie {
           trie *map<char,trie> child ;
           bool isLeaf;
           
           trie() {
                for(auto char : child) {
                    child[char] = NULL;
                }
               isLeaf = false;
           }
       }
       
       void insert(trie * root,string &s, int st){
         
         for(int i = st ; i < s.size(); i++ ) {
             if(root->child[s[i]] == NULL) root->child[s[i]] = new trie();
             root = root->child[s[i]];
         }
         root->isLeaf = true;
       }
       
       bool search(trie * root, string & word, int st) {
           for(int i = 0 ; i < word.size(); i ++) {
               if(root->child[word[i]] == NULL) return false;
               
               root = root->child[word[i]];
           }
           
           return true;
       }
       
       int main() {
           int n;
           cin>>n;
           vector<string> BusinessName;
           
           for(int  )// input
           
           string searchTerm; 
           
           for(auto name : BusinessName) {
               trie * root  = new trie();
               insert(name,root,0);
               
               for(int i = 1; i +1 < name.size(); i++ ) {
                   if(name[i]== ' '){
                       insert(root,name,i+1);
                   }
               }
           }
           if(search(root,searchTerm)){
               cout<<name<<endl;
           }
           
           
       }   
    
    
    
    


----------------------------------
/*
Q1. HeadToTail

In this puzzle game, sometimes called Word Ladder, the goal is to find a path of words between two English words with two simple rules:
- You can change only one letter at a time
- Every word in the steps has to be a valid English word.
Here is an example, going from "HEAD" to "TAIL" (make sure to emphasize which letter is changed on each step):
- HEAD
- HEAL
- TEAL
- TELL
- TALL
- TAIL

bool EnglishDictionary.isValidWord(String word);
*/
  static class Pair<T,U> {
      T left;
      U right;
      public Pair(T left,U right){
          this.left = left;
          this.right = right;
      }
      public <T,U> T getLeft(){
          return (T) this.left;
      }
            public <T,U> T getRight(){
          return (T) this.right;
      }
  }
      class Node {
        String CurrWord;
        List<String> path = new ArrayList();
        public Node(string CurrWord,List<String> prevPath) {
            path.addAll(prevPath);
            path.add(currWord);
            this.CurrWord = CurrWord;
        }
  
  private List<Pair<String,Integer>> getNeighbors(Set<string> visited,Node node){
      String cur = node.currWord;
      List<Pair<String,Integer>> neighbors = new ArrayList<>();
       for(int i = cur.size; i > 0; i --) {
           for(int j = 0; j< 26;j ++  ){
               String temp = cur;
               if (cur[i]!='A'+j) {
                   temp[i]='A'+j;
                   if(isValidWord(temp)) {
                          //add to neighbor
                       
                     neigbors.add(new Pair<>(temp,i));
                   }
               }
           }
       }
    return neighbors;
      
      
  }

        public List<String> getPath(Set<String> dev, String beginword,String endWord) {
            Queue<Node> q = new LinkedList<>();
            List<String> path = new ArrayList<>();
            q.add(new Node(beginword,path));
            Set<String> visited = new HashSet<>();
            
            visited.add(beginword);
            while(!q.isEmpty()) {
                
                
                Node curr = q.poll();
                
                if(curr.CurrWord.equals(endWord)){
                    System.out.println(curr.path);
                    return curr.path;
                }
                for(Pair<String,Integer> neighbour : getNeighbour(visited,curr)) {
                    q.add(new Node
                }
            }
            
        }
        
    }



