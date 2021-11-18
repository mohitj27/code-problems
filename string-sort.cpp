// Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

// Input Format
// Enter a number N , add N more numbers

// Constraints
// None

// Output Format
// Display the Boolean result

// Sample Input
// 4
// 1
// 2
// 2
// 1
// Sample Output
// true

#include<iostream>
using namespace std;
string isPalindrome(string st){
	int n = st.length();
	for(int i=0;i<n/2;i++){
		if(st[i]!=st[n-i-1]) 
		return "false";
	}
	return "true";
}
int main() {
	int n;
	cin>>n;
	char ch;
	string st;
	for(int i =0;i<n; i++){
     cin>>ch;
	 st += ch;
	}
	
	string result = isPalindrome(st);
	cout<<result<<endl;
	return 0;
}