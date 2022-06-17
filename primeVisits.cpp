// Sieve Approach - generate an array 
//containing prime numbers

#include <bits/stdc++.h>

using namespace std;

void prime_sieve(int *p) {

 // first mark all odd numbers as prime
   for(int i = 3; i < 1000000; i+=2 ) {
   	p[i] = 1;
   }

   for(long long i =3; i <= 1000000; i +=2) {

    if(p[i] == 1) {


    	for(long long j = i*i; j <= 1000000 ; j += i) {
           p[j] = 0;
           
    	}
    }



   }

   // special case


   p[1] = p[0] = 0;
   p[2] = 1;

}



int main() {


   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
    
  int n; 

  cin>>n;

  int p[1000005] = {0};

   prime_sieve(p);

   int csum[1000005] = {0};
  for(int i = 1; i <= 1000000; i++) {
    csum[i] = csum[i-1] + p[i];
  }

  int q;
  cin>>q;

  while(q--) {

   int a, b;

   cin>>a >>b;

   cout<< csum[b] - csum[a-1] <<endl;

  }


	return 0;
}