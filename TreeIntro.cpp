#include <iostream>

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
	return max(ls,hs) + 1; 
}

int printKthLevel(node*root,int k) {
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
int diameterOp(node *root){

}
class Pair{
public:
	int height;
	int diameter;

}
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
int main() {

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    node * tree = buildTree();

    print(tree);

    return 0;
}