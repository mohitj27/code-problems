#include <iostream>

using namespace std;

int main() {

   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  
   int n; 

   cin>>n;
   
   int a[n];
    int twoUniqueNos = 0;
   for(int i =0; i < n; i++) {
    cin>>a[i];

    twoUniqueNos = twoUniqueNos^a[i];
   }

   // two Unique nos m do unique no h abhi mere paas meko 
     // ab dono no ko find karna h 
   // agar usme ek bit set h to result m b ek bit set hogi
   // so 
   //
   int temp = twoUniqueNos;
   int bitPos = 0;
   while( (temp&1) != 1 ) {
      bitPos++;
      temp = temp>>1;
   }

   int mask = 1<<bitPos;

   int firstNumber = 0;
   int secondNumber = 0;

   for(int i =0 ; i < n ; i++) {

   	if( (a[i]&mask) > 0 ) {
      firstNumber = firstNumber^a[i];
   	}
   }
     secondNumber = firstNumber^twoUniqueNos;

     cout<<firstNumber<<" "<<secondNumber;



	return 0;
}