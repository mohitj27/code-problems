// find subsequencof string


#include <iostream>

using namespace std;


void filterChars(int n, char a[]) {

	int j =0;

	while(n >0) {
		int lastBit = (n &1);
		if (lastBit) {
			cout<<a[j];
		}

		j++;
		n = n>>1;
	}

	cout<<endl;
}
void printSubsets(char a[]) {


	int n = strlen(a);

	for(int i =1; i < (1<<n) ; i ++) {
		filterChars(i,a);
	}
}

int main() {
   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
  
	char a[100];

	cin>>a;

	printSubsets(a);

	return 0;
}