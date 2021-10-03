#include <bits/stdc++.h>

using namespace std;

class Queue{

   stack<int> s1;
   stack<int> s2;
   public:
       void push1(int element){
          s1.push(element);
       }
       void pop1() {
          if(s1.empty()){
            return;
          }
          while(s1.size()>1) {
            int ele = s1.top();
            s1.pop();
            s2.push(ele + 2);

          }
          s1.pop();
          swap(s1,s2);
       }

       int front1() {
                 if(s1.empty()){
            return 0;
          }
          while(s1.size()>1) {
            s2.push(s1.top());
            s1.pop();
          }
          int element = s1.top();
          s1.pop();
          s2.push(element);
          swap(s1,s2);
         return element;


       }

};

int main() {

       Queue q;
        //q.push(1);
        q.push1(2);
        q.push1(3);

       cout<<q.front1();
       q.pop1();
       cout<<q.front1();

       return 0;

}
