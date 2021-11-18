// 

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void StringASCIIdifference(string str) {

//int ascii;

for(int i=0; i<str.length()-1; i++) {

    //ascii=str[i+1]-str[i];

    cout<<str[i]<<str[i+1]-str[i];

}

cout<<str[str.length()-1];
}

int main() {

string str;



getline(cin, str);

if(str.length()>2 && str.length()<1000)

    StringASCIIdifference(str);

return 0;
}