// One of the important aspect of object oriented programming is readability of the code. To enhance the readability of code, developers write function and variable names in Camel Case. You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.

// Input Format
// A single line contains the string.

// Constraints
// |S|<=1000

// Output Format
// Print words present in the string, in the order in which it appears in the string.

// Sample Input
// IAmACompetitiveProgrammer
// Sample Output
// I
// Am
// A
// Competitive
// Programmer
// Explanation
// There are 5 words in the string.

#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	string result[100];
	getline(cin,str);
    int k = 0;
	result[k] += str[0];
	for(int i =1; i<str.length(); i++){
         if(isupper(str[i])){
			k = k+1;
			result[k] += str[i]; 
		 }
		 else {
			 result[k] += str[i];
		 }


	}
	int n = sizeof(result)/sizeof(result[0]);

    for(int i =0;i<n; i++ ){
		cout<<result[i]<<endl;
	}

	return 0;
}