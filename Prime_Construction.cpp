#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    long long int value;
    vector<long long int> inputs;
	while(cin>>value){
		cout<<value;
        inputs.push_back(value);
	}
	int q = inputs[inputs.size()-1];
    
    long long int ans = 1;

    for(int i=0; i<inputs.size()-1;i++){
    	ans = ans*inputs[i];
    }
     auto loopEnd = max_element(inputs.begin(), inputs.end()-1);
    for(int i=0; i <loopEnd ;  )


	return 0;
}