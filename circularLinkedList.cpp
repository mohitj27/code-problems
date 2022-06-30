#include <bits/stdc++.h>

using namespace std;

class node{
public: 
	int data;
	node *next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insert(node*&head,int data){

	 node* n = new node(data);

	 node*temp = head;

	 n->next = head;
	 if(temp!= NULL){

		while(temp->next!= head){
		
			temp = temp->next;
		
		}
		temp->next = n;


	}else {
		n->next = n;
	}
	head = n;

}
void print(node*head){
	node*teamp = head;
	while(temp->next!= head){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
	return;
}
// deletion in circular Linked list 
int main() {
  


	return 0;
}