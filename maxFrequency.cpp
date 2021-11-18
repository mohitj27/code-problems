#include <bits/stdc++.h>
#define ASCII_SIZE 256
using namespace std;


char maxFrequency(char *str){
   
 int count[ASCII_SIZE] = {0};


 int len = strlen(str);
 int max =0;
 char result;

    for (int i =0; i <len;i++){
      count[str[i]]++;
      if(max<count[str[i]]){
          max = count[str[i]];
          result = str[i];
      }

    }
    return result;

}

int main() {
    char a[1000];

    cin>>a;
    char result = maxFrequency(a);

    cout<<result<<endl;

    return 0;

}