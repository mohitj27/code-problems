#include <bits/stdc++.h>


using namespace std;

int charToDigit(char ch){
	return ch - '0';
}

char digittoChar(int digit) {
	return digit + '0';
}
string addNumbers(string n1,string n2) {

	if(n1.length() > n2.length()){
		swap(n1,n2);
	}

	string result = "";

	reverse(n1.begin(),n1.end());
	reverse(n2.begin(),n2.end());

	// Add digits
	int carry = 0;
	for(int i=0; i < n1.length(); i++){
		int d1 = charToDigit(n1[i]);
		int d2 = charToDigit(n2[i]);
		int sum = d1+d2 + carry;
		int output_digit = sum %10;

		carry = sum/10;

		result.push_back(digittoChar(output_digit));
	}
	for(int i = n1.length(); i < n2.length(); i++) {
		int d2 = charToDigit(n2[i]);
		int sum = d2+ carry;
		int output_digit = sum%10;
		carry = sum/10;

		result.push_back(digittoChar(output_digit));

	}
	if(carry) {
		result.push_back('1');
	}
	reverse(result.begin(),result.end());

	return result;
}

int main() {
    
    // String
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    

    string s1,s2;

    cin>>s1>>s2;

    string result = addNumbers(s1,s2);
   
    cout<<result;
	return 0;
}