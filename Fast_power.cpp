#include <bits/stdc++.h>

using namespace std;



int power(int a, int n) {

	if(n == 0 ) return 1;

	return a*power(a,n-1);
}

int fast_power(int a, int n) {

   if (n == 0) return 1;


   int subAns = fast_power(a, n/2);

   subAns *= subAns;

   if(n&1) return  subAns*a;

   return subAns;

}

int main() {

	int a,n;

	cin>>a>>n;
   
      fast_power(a,n);

	return 0;
}