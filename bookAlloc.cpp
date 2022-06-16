#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;


bool BooksRakhPayee(int *Books, int noOfBooks,int noOfStudents,int curr_min) {
	int Student = 1;

	int noOfPages = 0;

	for(int i=0; i<noOfBooks;i++) {
		if(noOfPages + Books[i] > curr_min) {
			  Student++;
			noOfPages = Books[i];
			if(Student > noOfStudents) {
				return false;
			}
		}
		else {
			noOfPages += Books[i];
		}
	}

	return true;
}

int BookAllocation(int *Books,int noOfBooks,int noOfStudents){
   int start = Books[noOfBooks-1];

   long long end = accumulate(Books,Books+noOfBooks,0);
   int ans = INT_MAX;
   while(start <=end) {
   int mid = (start+end)>>1;

   if(BooksRakhPayee(Books,noOfBooks,noOfStudents,mid)) {
       
       ans = min(ans,mid);

        end = mid-1;
   } 
   else {
   	    start = mid + 1;
   }


   }

   return ans;


}


int main() {
  
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
int t;
cin>>t;

while(t--) {

int noOfStudents,noOfBooks;

cin>>noOfBooks>>noOfStudents;

int *Books = new int[noOfBooks];

for(int i=0;i<noOfBooks;i++) {

	cin>>Books[i];
}

cout<<BookAllocation(Books,noOfBooks,noOfStudents)<<endl;


}
 return 0;
}