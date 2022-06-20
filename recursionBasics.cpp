// Parts of recursive algorithm
// --------  
// 1. Base case
// 2. Recursive Call (to work towards base case)

#include <iostream>


using namespace std;


int fact (int n) {

	if(n == 0) {
		return 1;
	}

	return n*fact(n-1); 
}

int f(int n) {

	if (n == 0 or n == 1) {
		return n;
	}

	// rec case  

	int f1 = f(n - 1);
	int f2 = f(n- 2);

	return f1 + f2;
}

void printD(int n) {

	if(n == 0) return;

	cout<<n<< " ";

	 printD(n-1);
}

void printI(int n) {

	if(n == 0) return;

	printI(n-1);

	cout<<n<<" ";
}

bool isSorted(int a[], int n) {

	if (n == 0 or n == 1) return true;

	if(a[0]<a[1] and isSorted(a+1, n-1)) return true;


	return false;
}


int main() {



    
	return 0;
}