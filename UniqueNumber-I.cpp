#include <iostream>


using namespace std;


int main() {

   int n;

   cin >>n;

   int temppInput;

   int ans = 0;

   for(int i =0 ;i <n; i ++) {
    cin>>temppInput;

    ans = ans ^ temppInput;

    

   }
   cout<<temppInput<<endl;


	return 0;
}