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

// Linked Class  (OOP)

// class LinkedList {
// 	node *head;
// 	node *tail;

// public:
// 	LinkedList(){

// 	}
// 	void insert(int d)
// }

void build() {

}

void insertAtHead(node*&head,int d) {
   if(head == NULL) {
   	head = new node(d);
   	return;
   }
   node *n = new node(d);
   n->next = head;
   head = n;

}
int length(node*head){
	int cnt =0;
	while(head!= NULL) {
		// cout<<head->data<<"- >";
		head = head->next;
	   cnt++;
	}
	return cnt;
}
void insertAtTail(node*&head,int data) {
	if(head == NULL){
		head = new node(data);
		return;
	}

	node *tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = new node(data);
	return;
}
void insertInMiddle(node*&head,int data,int p){
	if(head == NULL or p==0){
		insertAtHead(head,data);
	}
	else if(p>length(head)){
		insertAtTail(head,data);
	}
	else {
		int jump = 1;
		node *temp = head;

		while(jump <= p-1) {
			temp = temp->next;
			jump++;
		}
		node * n = new node(data);
		n-> next = temp->next;
		temp->next = n;
	}
}
void print(node*head){
	while(head!= NULL) {
		cout<<head->data<<"- >";
		head = head->next;
	}
}
void deleteHead(node*&head){
	if(head == NULL){
		return;
	}
	node *temp = head->next;
	delete head;
	head = temp;
	
}
bool search(node *head,int key){
	node*temp = head;

	while(temp!= NULL){
		if(head->data == key) return true;

		head = head-> next;
	}
	return false;
}
// recursively 
bool searchRecursive(node*head,int key) {
	if(head == NULL) return false;

	if(head->data==key){
		return true;
	} else {
		return searchRecursive(head->next,key);
	}
}

node* take_input_2(){
   int d;
   cin>>d;
    node*head = NULL;
   while(d!=-1){
     insertAtHead(head,d);
     cin>>d;
   }
   return head;
}


ostream& operator<<(ostream &os,node*head){
	print(head);
    return os;
}

istream& operator>>(istream &is,node*&head){
	head = take_input_2();
	return is;
}

void reverse(node*&head) {
	node*C = head;
	node* P = NULL;

	node*N;

	while(C!= NULL){

		N = C->next;

		C->next=P;

		P = C;
		C = N;
	}
	head = P;
}

// recursively reverse a linked list

node* recReverse(node*head){
    if(head->next == NULL or head==NULL){
    	return head;
    }
   
   node* shead = recReverse(head->next);

   node *temp = head->next;
   head->next = NULL;
   temp->next = head;
  
   return shead;
}
   node* midpoint(node*head){
   	if(head==NULL or head->next == NULL){
   		return head;
   	}
   	node*slow = head;
   	node*fast = head-> next;

   	while(fast->next!=NULL and fast!=NULL) {
   		fast = fast->next->next;
   		slow = slow->next;
   	}
   
      return slow;
   }
   node* kthPositionFromEnd(node *head, int k){
   	if(head ==NULL or head->next == NULL) 
   		return head;

   	node* slow = head;
   	node* fast = head;
   while(k!=0){
   	 fast = fast->next;
   }
   while(fast!=NULL and fast->next!= NULL){
   	slow = slow->next;
   	fast = fast->next;
   }

    return slow;

   }

node* merge(node*a,node*b){

   	if(a==NULL) return b;

   	if(b==NULL) return a;

   	node*c;
    if(a->data < b->data){
    	c = a;
    	c->next = merge(a->next,b);
    } else {
    	c = b;
    	c->next = merge(a,b->next);
    }
    return c;
}
// merge sort on linked list
node* mergeSort(node *head) {
	if(head==NULL or head->next==NULL) return head;

	node* mid = midpoint(head);
	node* b = mid->next;
    node* a = head;

    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node* c = merge(a,b);

    return c;

}
// Cycle detection and removal (Floyd's cycle) It should complete 
bool detectCycle(node* &head) {
	node*slow = head;
	node*fast = head;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow) { 
        
         removeCycle(slow,head);
      
			return true; }

	}

	return false;

}

void removeCycle(node* slow,node* &head ) {
   
   node* ptr1 = slow;

   node* ptr2 = head;

   node* prev = ptr1;

   while(ptr2!= ptr1){
      
      prev = ptr1;
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;    
     
      


      
   }

    prev->next = NULL;


}


int main() {
    
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    node *head = take_input_2();

	// node*head = take_input_2();
 //    node*head2 = take_input_2();
 //    node *head,*head2;
 //    cin>>head>>head2;
	// cout<<head;
	// cout<<head2;
	// cout<<head<<head2;
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,3);
    // insertInMiddle(head,5,2);

     // print(head);

}
