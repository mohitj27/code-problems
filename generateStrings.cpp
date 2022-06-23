#include <bits/stdc++.h>

using namespace std;

void generateStrings(char *in,char *out,
	int i, int j) {
   
   if(in[i] == '\0'){

   	out[j] = '\0';

   	cout << out <<endl;

   	return;
   }
   
   // rec case

   int digit = in[i] - '0';
   if (digit!= 0) {
   char ch = digit + 'A' - 1;
   out[j] = ch;

   generateStrings(in,out,i+1,j+1);
  }
   if(in[i+1]!= '\0') {
      
      int secondDigit = in[i+1] - '0';

      int no = digit*10 + secondDigit;
      if(no <= 26) {
      	char ch = no + 'A' - 1;
      	out[j] = ch;
      	generateStrings(in,out,i+2,j+1);
      }

   }

   return;

}

int main () {

   #ifndef ONLINE_JUDGE
     // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    char a[100];

    cin>>a;

    char out[100];

    generateStrings(a,out,0,0);



	return 0;
}