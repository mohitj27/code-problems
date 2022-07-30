#include <bits/stdc++.h>

using namespace std;

void stockSpan(int prices[],int n,int span[]){

    stack<int> s;
    s.push(0);

    span[0] = 1;

    for(int i = 1; i <=n-1; i++){
   int currentPrices = price[i];
   while(!s.empty() and price[s.top()] <= currentPrices){
   	s.pop();
   }
   if(!s.empty){
     int prev_highest = s.top() ;
     span[i] = i-prev_highest;  	
   } else {
   	span[i] = i+1;
   }
   s.push(i);

    }



}

int main() {
    
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
  
  int prices[] = {100,80,60,70,60,75,85};

  int n = sizeof(prices)/sizeof(int);

  int span[100000] = {0};


  return 0;



}