#include <bits/stdc++.h>

using namespace std;

//Binary Search tree 
// search is expensive in binary tree
// BST - 
// - > binary tree
// - > element are ordered
// - > each subset is a bst

class node {
public:

	int data;
	node *left;
	node *right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
node * insertInBST(node *root,int data){
	 if(root == NULL) return new node(data);

	 if(data <= root->data){
	 	root->left = insertInBST(root->left,data);
	 }
	 else {
	 	root->right = insertInBST(root->right,data);
	 }
	 return root;
}

node *buildBSTfromPreorder(int pre[], int key,int min,int max,int size){

static int preIndex = 0;
node * root = NULL;
if(preIndex >=size) return NULL;

if(key> min and key <max) {
   root = new node(key);
   preIndex ++;
   if(preIndex < size) {
   	root->left = buildBSTfromPreorder(pre,pre[preIndex],min,key,size);
   }
   if(preIndex < size) {
   	root->right = buildBSTfromPreorder(pre,pre[preIndex],key,max,size);
   }
}

return root;
}

node * build(){
	// Read numbers till -1

	int d;
	cin>>d;
	node *root = NULL;

	while(d!= -1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
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
void inorder(node *root){
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->data<<",";
	inorder(root->right);
}
bool search(node *root,int data) {
	if(root == NULL) return false;
   if(root->data == data) return true;

   if(data<= root->data) {
   	return search(root->left,data);
   }else{
   	return search(root->right,data);
   }

}

// deletion 
// three cases - 
// - 0 children 
// 1 child
// 2 children
node *deleteInBST(node*root,int data){
	if(root==NULL) return NULL;
		else if(data<root->data){
			root->left = deleteInBST(root->left,data);
		   return root;
		} else if(data == root->data){
         if(root->left == NULL and root->right ==NULL){
         	delete root;
         	return NULL;
         }
         if(root->left!= NULL && root->right==NULL){
         	node *temp = root->left;
         	delete root;
         	return temp;
         }
            if(root->right!= NULL && root->left==NULL){
         	node *temp = root->right;
         	delete root;
         	return temp;
         }
         node *replace = root->right;
         while(replace->left!=NULL){
         	replace = replace->left;
         }
         root->data = replace->data;
         root->right = deleteInBST(root->right,replace->data);
		}else{
			root->right = deleteInBST(root->right,data);
		   return root;
		}

}
bool isBST(node *root,int minV = INT_MIN,int maxV = INT_MAX){
	if(root == NULL) return true;

	if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) &&
		isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

class LinkedList {
public:
	node *head;
	node*tail;
};

LinkedList flatten(node *root) {
	LinkedList l;
	if(root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}

	if(root->left == NULL & root->right == NULL){
		l.head = l.tail = root;
		return l;
	}
	if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = flatten(root->left);
	   leftLL.tail->right = root;
	   l.head = leftLL.head;
	   l.tail = root;
	   return l;
	}
	if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = flatten(root->right);
	   root->right = rightLL.head;

	   l.head = root;
	   l.tail = rightLL.tail.
	}
	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);

	leftLL.tail->right = root;
	root->right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;

	return l;

}


int main(){
     

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    node *root = build();
    inorder(root);
    cout<<endl;
    bfs2(root);
     
     int s;
     cin>>s;
     root = deleteInBST(root,s);
     inorder(root);
     bfs2(root);
     if(isBST(root)) cout<<" HASHAHAHAHAHAH";
     // if(search(root,s)) cout<<"present";
     // else cout<<"Not Present";
   

	return 0;
}