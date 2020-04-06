#include <iostream>
#include <stack>

using namespace std;

int main() {
     int n;
     cin>>n;


     while(n--) {

      stack<int> a;

      int query,price;

      cin>>query;

      if(query == 2) {
        cin>>price;
        a.push(price);

      }
      if(query == 1) {

        if(!a.empty()){
            cout<<a.top()<<endl;
            a.pop();
        } else {
            cout<<"No Code"<<endl;
        }
      }

     }
   return 0;
}
