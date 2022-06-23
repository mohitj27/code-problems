#include <bits/stdc++.h>

using namespace std;


// Replace "Pi" with "3.14"

void replacePi(char a[], int i) {
	if(a[i]=='\0' or a[i+1] == '\0') return;

	if(a[i] == 'p' and a[i+1] == 'i') {
		// shifting + replacement
      int j = i +2;

      while(a[j] != '\0') {
      	j++;
      }

      while(j >= i+2) {

      	a[j+2] = a[j];

      	j--;
      }
      a[i] = '3';
      a[i+1] = '.';

      a[i+2] = '1';
      a[i+3] = '4';

      replacePi(a,i+4);

	}
	else {
		replacePi(a,i+1);
	}
}

int main() {




	return 0;
}