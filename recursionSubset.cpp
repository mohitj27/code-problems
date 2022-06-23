#include <iostream>

  void generateSubsequence(char *in, char *out, int i, int j){
    
    if(in[i] == '\0') {
      
      out[j] = '\0';

      cout<< out;

      return;
  

    }


    out[j] = in[i];

    generateSubsequence(in,out,i+1, j+1);

    generateSubsequence(in, out, i+1, j);



  }

  int main() {


  	char input[] = "abc";

  	char output[10];

  	generateSubsequence(input, output, 0,0);
  }