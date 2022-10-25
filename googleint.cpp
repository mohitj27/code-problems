
[.  
  ["I", "am", "Sam"],
  ["Sam", "I", "am"],
  ["I", "like", "green", "eggs", "I", "like", "and", "ham"]
  ,
]

predict('I')
    map < string, list< int, string> > word ; 
  I - key     value 
             list - am - 2
             like - 1
    
    for(auto ans : word['I']) {
         for( auto res : ans) {
           
         }
    }
     
    I  - AM , LIKE  
    
    #include <bits/stdc++.h> 
    
    using namespace std;
    class Predictor {
      vector<vector<string>> words;
      int row, col;
      void prepare() {
          
        cin>>row>>col;
        int elementsofar = 0;
        for(int i= 0; i < row; i++ ) {
             for(int j = 0; j < col; j++) {
               cin>>words[i][j];
        }
          
          
      map< string , string > ans ; 
      
      map < string , list <  int > temp;
      
      for (int i = 0; i < row; i++ ){ {
        for(int j = 0; j < col ; j ++) {
          temp.first.insert(make_pair(words[i][j],words[i][j+1])); 
          temp.second ++; 
      
          
          }
      
      }
      }
      
    string predict(string word) {
      
    
    }
     
        };  
    int main() {
       
      char words[100][100];
      
      // input 
      
      
    
      return 0;
    }
