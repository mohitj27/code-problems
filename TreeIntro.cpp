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

node* insert(){
	int d;
	string value;
	cin>>d;
	cin>>value;
	node* root=new node(d);
	if(value=="true"){
		root->left=insert();
	}
	cin>>value;
	if(value=="true"){
		root->right=insert();
	}
	return root;
}
bool isIdentical(node *root1,node *root2){   
    if(root1==NULL&&root2==NULL)
            return true;
    if(root1!=NULL&&root2!=NULL){  
        bool lt=isIdentical(root1->left,root2->left);
        bool rt=isIdentical(root1->right,root2->right);
        return (lt && rt);        
    }
    return false;
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

node * inputLevelWise(vector<int> a){
  
  queue<node *> q;
  int n = a.size();
  node * curNode =  NULL;
  node * root = new node(a[0]);
  int count = 0;
  q.push(root);
  for(int i =1; i <n;i++){
  	node *tempNode = NULL;
  	if(a[i]!= -1) { 
     tempNode = new node(a[i]);}
     
     if(count == 0) {
     curNode = 	q.front();
     q.pop();
     }
     if(count ==0) {
     	count++;
       curNode->left = tempNode;
     } else {
     	count =0;
     	curNode->right = tempNode;
     }

     if(a[i] != -1 ){

     	q.push(tempNode);
     }
  
  }  
  return root;
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

 	root->data = leftSu
 	m + rightSum;

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

  
  void printLeftView(node *root,int level,
  	int &maxlevel) {
    
    if(root == NULL)
    	return;

    if(maxlevel<level) {
    	cout<< root->data << " ";

    	maxlevel = level;
    }
    // left

    printLeftView(root->left,level+1,maxlevel);

    //right

    printLeftView(root->right, level + 1 , maxlevel);



  }
  void printAtLevelK(node*root,int k) {
	if(root == NULL) return;

	if(k==0) {
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
	return;
}
int printtAtDistanceK(node*root,node*target,int k) {

if(root == NULL) {
	return -1;
}	
// reach the target node

if(root == target){
	printAtLevelK(target,k);
	return 0;
}
// next step - ancestor
int DL = printtAtDistanceK(root->left,target,k);
if(DL!= -1){
	// Again there are two cases
	// ancestor itself or you need to go right ancestor
	if(DL + 1 == k){
		cout<<root->data<<" ";
	} else {
		printAtLevelK(root->right,k-2-DL);
	}
	return 1+DL; 
}
int DR = printtAtDistanceK(root->right,target,k);
if(DR!=-1){
	if(DR+1 ==k){
		cout<<root->data<<" ";
	}
   else{
   	printAtLevelK(root->left,k-2-DR);
   }	
   return 1+DR;
}
return -1;
}

node * lca(node*root,int a,int b){

	if(root == NULL) return NULL;

	if(root->data == a or root->data == b) {
		return root;
	}
	node *leftans = lca(root->left,a,b);
	node *rightans = lca(root->right,a,b);
	if(leftans != NULL and rightans != NULL) return root;

	if(leftans != NULL) return leftans;

	return rightans;
}
// finding the level of given node
int search(node *root,int key,int level) {
	if(root == NULL) return -1;

	if(root->data == key) return level;
   int left = search(root->left,key,level+1);
   if(left != -1) return left;

   return search(root->right,key,level+1);

}

int findDistance(node *root,int a,int b){ 
    
  node *lca_node = lca(root,a,b);
  int l1 = search(lca_node,a,0);
  int l2 = search(lca_node,b,0);
  return l1+l2;
	}

void verticalOrderPrint(node *root,int d,map<int,vector<int> > &m){
  if(root ==NULL) return;

  m[d].push_back(root->data);
   
  verticalOrderPrint(root->left,d-1,m);
  verticalOrderPrint(root->right,d+1,m);
   return; 
}
class NewPair{
	public:
	int branchSum;
	int maxSum; 

	NewPair() {
		branchSum = 0;
		maxSum = 0;
	}
};
NewPair maxPathSumFromAnyNode(node *root) {
    NewPair p;
	if(root == NULL) return p;

	NewPair left = maxPathSumFromAnyNode(root->left);
	NewPair right = maxPathSumFromAnyNode(root->right);

	// construct two values

	int op1 = root->data;
	int op2 = left.branchSum + root->data;
	int op3 = right.branchSum + root->data;
	int op4 = left.branchSum + right.branchSum + root->data;

	int current_ans_through_root = max(op1,max(op2,max(op3,op4)));

	// branch sum of root

	p.branchSum = max(left.branchSum,max(right.branchSum,0)) + root->data;

	p.maxSum = max(left.maxSum,max(right.maxSum,current_ans_through_root));

	return p;

}



int main() {

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    map<int , vector<int> > m;
    int d = 0;
    int t;
    vector<int> input;
    while(cin>>t){
    	input.push_back(t);
    }
    

    node * tree = inputLevelWise(input);
     bfs2(tree);
    // cout<<" max Sum Path"<<maxPathSumFromAnyNode(tree).maxSum<<endl;
      verticalOrderPrint(tree,d,m);
     for(auto p : m){


     	cout<<p.second[p.second.size()-1]<<" ";


     }
    // // node * tree = buildTree();
    // int rightView = 0;
    // int leftView = 0;
    // node* target = tree->left;

    // printtAtDistanceK(tree,target,2);
    // printRightView(tree,1,leftView);
    // printLeftView(tree,1,rightView);
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

    // int ind[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    // int post[] = {8, 4, 5, 2, 6, 7, 3, 1}; 
    // int k = sizeof(ind)/sizeof(int);

    // node *root = createTreeFromTravPos(ind,post,0,k-1);
    // bfs2(root);
    return 0;
}

function foo(items) {
  var i;
  for (i = 0; i < items.length; i++) {
    alert("Welcome To LiveCode " + items[i]);
  }
}

// Given an unsorted integer array, return the smallest missing positive integer. Implementing this in O(n) time complexity and O(1) space constant.
// [2, 5, 45, -4, 1, 4] -> 3
              
       2, 5, 45, 1,4,-4
       a[]

// i = 1; i++
// int i =1; 

int findMissingPositive(vector<int> arr) {
    
    int s = arr.size();
    
    for(int i =0; i < s; i ++) {
        
        if(arr[i] < 0 || arr[i] == 0 ) {
            arr[i] = s+1;
        }
        if((abs(arr[i]) - 1 < s ) and a[abs(arr[i]) - 1] > 0  ) {
            arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
            
        }
    }
    
    for(int i = 0; i <s; i++) {
        if(arr[i] > 0) return i + 1;
        
        return s+1; 
    }
    
    
}






