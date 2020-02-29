#include <iostream>
#include <list>
using namespace std;

//template <typename T>
/*
int search(T arr[], int n, T key){

for(int i=0; i < n; i++) {
    if(arr[i] == key) {
            cout<<"Hello";
        return i;
    }
}
    return n;

}
*/

template <class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){

    while(start!=end){

    if(*start == key)
    {return start;
    }
       start++;
    }
     return end;
}
 int main() {
/* float a[] = {1.1,1.2,1.3};
 float k = 1.2;
 cout<<search(a,3,k);
*/
list<int> l;
l.push_back(1);
l.push_back(3);
l.push_back(6);
l.push_back(8);
   list<int> :: iterator it = search(l.begin(),l.end(),4);
   cout<<*it;

   return 0;

 }
