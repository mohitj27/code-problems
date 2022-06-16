

// #include<bits/stdc++.h>
#include <iostream>
using namespace std;


void increment(int *aptr){
	*aptr = *aptr +1;

	cout<<"inside function"<<*aptr;
}
int main() {



	int x =10;

	int *xptr;

	xptr = &x;

	 cout<< *(&x) <<endl;

	 cout<< *xptr<<endl;

	 cout<<*(&xptr)<<endl;
     
     cout<<&(*xptr) << endl;
     // double pointer
     int **xxptr = &xptr;

     cout<<xxptr;

   //  pass by reference using   pointer
      int a = 10;
      increment(&a);

      cout<<"inside main : "<<a;
     return 0;
}