#include <bits/stdc++.h>

using namespace std;

int stringToInt(char *a, int n) {

  if(n ==0) return 0;

  int digit = a[n-1] - '0';
  int small_ans = stringToInt(a,n-1);

    return small_ans*10 + digit;

}


int main() {

    
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  

    char a[] = "1234";

    int len = strlen(a);

    cout<<stringToInt(a,len);




	return 0;
}