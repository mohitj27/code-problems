
#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	 int N;
	cin>>N;
	long long  int *a = new long long int[N];
	for(int i =0; i <N; i++ ){
		cin>>a[i];
	}
	cout<<*max_element(a,a+N)<<endl;
	return 0;
}
