#include <iostream>

using namespace std;

bool isOdd(int n, int i) {

  return n & 1;


}

int getBit(int n, int i) {

	int mask = (1<<i);

	return  (n & mask) > 0 ? 1 : 0;
}

void setBit(int &n, int i) {

	int mask = (1<<i);

	n = n |mask;
}

void clearBit(int &n, int i){

int mask = ~(1<<i);

n = n & mask;

}

void updateBit(int &n, int i,int v) {

clearBit(n,i);

n = n | (v<<i);


}

int clearLastIBits(int n, int i) {
   
   int mask = (-1 << i);

   return n & mask;
}

int clearRangeItoJ(int n, int i, int j) {

	int ones = (~0);
	int a = ones<<(j+1);
	int b = (1<<i) - 1;

	int mask = a|b;

	int ans = n&mask;

	return ans;
}

int main() {

  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif


    int n = 6;

    int i = 0;

    cout << isOdd(n,i)<<endl;

    cout<<getBit(n,i)<<endl;
    setBit(n,i);
    cout<<n<<endl;



	return 0;
}