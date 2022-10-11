// three integers A,B and C compare pow(A,C) and pow(B,C)
// if pow(A,C) < pow(B,C) return < ; else if > , and at last  return =

#include <bits/stdc++.h>

using namespace std;

int pow(int a,int b) {
	int result = 1;

	while(b!=0) {

        	if(b&1){
              result = result*a;

        	}	
        	a = a*a;
        	b  = b>>1;
	}
    
	return result;

}

string solve(int A,int B,int C) {

	string result = "";

    if(pow(A,C) < pow(B,C)) {
        result = '<';
    }
    else if(pow(A,C) > pow(B,C)) {

    	result = '>';

    }
    else {
    	result = '=';
    }


	return result;
}


int main() {
    
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int a,b,c;

    cin>>a>>b>>c;


    cout<<solve(a,b,c)<<endl;

 
	return 0;
}