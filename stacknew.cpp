#include <bits/stdc++.h>

using namespace std;

class Stack{
private:
	vector<int> v;

public:
	void push(int data){
		v.push_back(data);
	}
	bool empty(){
		return v.size()==0;
	}

	void pop(){
		if(!empty()){
			v.pop_back();
		}
	}

	int top(){

		return v[v.size() - 1];
	}
};

int main(){
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    Stack s;
     stack<int> s;

     for(int i =0; i <=5; i ++){
     	s.push(i);
     }
     while(!s.empty()){
     	cout<<s.top()<<",";
     	s.pop();
     }
    for(int i=1;i<=5;i++) {s.push(i*i);}

    	while(!s.empty()){
    		cout<<s.top()<<endl;
    		s.pop();
    	}

    



    return 0;

}