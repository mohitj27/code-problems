#include <bits/stdc++.h>

using namespace std;

bool isValidExp(char *s){

	stack <char> s;
	for(int i=0;s[i]!='\0';i++){

		char ch = s[i];

		if(ch == '('){
			s.push(ch);
		}
		else if(ch == ')'){
			if(s.empty() or s.top()!='('){
				return false;
			}
			s.pop();
		}
	}

	return s.empty();
}

int main() {


     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

   



	return 0;
}