#include <bits/stdc++.h>

using namespace std;
void duplicateCharFormatting(char a[], int i){

	if(a[i]=='\0' or a[i+1] == '\0') return;

	if(a[i] == a[i+1]) {
		int j = i + 1;

		while(a[j] != '\0' ){
			j++;
		}
		while(j >= i +1){
			a[j+1] = a[j];
			j--;
		}
		a[i+1] = '*';
		a[i+2] = a[i];
		duplicateCharFormatting(a,i+3);
	}
	else{
		duplicateCharFormatting(a,i+1);
	}

}
int main() {
   
       #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    char ch[10000];

    cin>>ch;
    duplicateCharFormatting(ch,0);
    cout<<ch<<endl;

	return 0;
}