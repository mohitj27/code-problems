// useful when we have no of queries to solve

#include <bits/stdc++.h>

using namespace std;
vector<int> prime_sieve(int *p) {

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
    vector<int> primes;

    primes.push_back(2);

    for(int i =3; i <= 1000000; i +=2) {
    	if(p[i] == 1) {
    		primes.push_back(i);
    	}
    }
    return primes;
}

 vector<int> factiorize(int m, vector<int> &primes) {

 	vector<int> factors;
 	factors.clear();

 	int i =0;
 	int p = primes[0];

 	while(p*p <= m) {
 		if(m%p == 0) {
 			factors.push_back(p);
 			while(m%p == 0) {
 				m = m/p;
 			}
 		}
 		i++;
 		p = primes[i];
 	}
 	if(m != 1) {
 		factors.push_back(m);
 	}
     return factors;
 }

int main() {
   

   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif

   int p[1000005] = {0};

   vector<int> primes = prime_sieve(p);

   int t;

   cin >> t;

   while(t--) {

   	int no;

   	cin>>no;

   	vector<int> factors = factiorize(no, primes);

   	for(auto f : factors) {
   		cout<< f << " " << endl;
   	}
   }




    return 0;	
}