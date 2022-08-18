

{"house", "cat", "hope", "hair"}

"ho" -> "house", "hope"
"cat" -> "cat"
"h" -> "house", "hope", "hair"
  
       
       struct trie {
           trie *map<char,trie> child ;
           bool isLeaf;
           
           trie() {
                for(auto char : child) {
                    child[char] = NULL;
                }
               isLeaf = false;
           }
       }
       
       void insert(trie * root,string &s, int st){
         
         for(int i = st ; i < s.size(); i++ ) {
             if(root->child[s[i]] == NULL) root->child[s[i]] = new trie();
             root = root->child[s[i]];
         }
         root->isLeaf = true;
       }
       
       bool search(trie * root, string & word, int st) {
           for(int i = 0 ; i < word.size(); i ++) {
               if(root->child[word[i]] == NULL) return false;
               
               root = root->child[word[i]];
           }
           
           return true;
       }
       
       int main() {
           int n;
           cin>>n;
           vector<string> BusinessName;
           
           for(int  )// input
           
           string searchTerm; 
           
           for(auto name : BusinessName) {
               trie * root  = new trie();
               insert(name,root,0);
               
               for(int i = 1; i +1 < name.size(); i++ ) {
                   if(name[i]== ' '){
                       insert(root,name,i+1);
                   }
               }
           }
           if(search(root,searchTerm)){
               cout<<name<<endl;
           }
           
           
       }   
    
    
    
    


----------------------------------
/*
Q1. HeadToTail

In this puzzle game, sometimes called Word Ladder, the goal is to find a path of words between two English words with two simple rules:
- You can change only one letter at a time
- Every word in the steps has to be a valid English word.
Here is an example, going from "HEAD" to "TAIL" (make sure to emphasize which letter is changed on each step):
- HEAD
- HEAL
- TEAL
- TELL
- TALL
- TAIL

bool EnglishDictionary.isValidWord(String word);
*/
  static class Pair<T,U> {
      T left;
      U right;
      public Pair(T left,U right){
          this.left = left;
          this.right = right;
      }
      public <T,U> T getLeft(){
          return (T) this.left;
      }
            public <T,U> T getRight(){
          return (T) this.right;
      }
  }
      class Node {
        String CurrWord;
        List<String> path = new ArrayList();
        public Node(string CurrWord,List<String> prevPath) {
            path.addAll(prevPath);
            path.add(currWord);
            this.CurrWord = CurrWord;
        }
  
  private List<Pair<String,Integer>> getNeighbors(Set<string> visited,Node node){
      String cur = node.currWord;
      List<Pair<String,Integer>> neighbors = new ArrayList<>();
       for(int i = cur.size; i > 0; i --) {
           for(int j = 0; j< 26;j ++  ){
               String temp = cur;
               if (cur[i]!='A'+j) {
                   temp[i]='A'+j;
                   if(isValidWord(temp)) {
                          //add to neighbor
                       
                     neigbors.add(new Pair<>(temp,i));
                   }
               }
           }
       }
    return neighbors;
      
      
  }

        public List<String> getPath(Set<String> dev, String beginword,String endWord) {
            Queue<Node> q = new LinkedList<>();
            List<String> path = new ArrayList<>();
            q.add(new Node(beginword,path));
            Set<String> visited = new HashSet<>();
            
            visited.add(beginword);
            while(!q.isEmpty()) {
                
                
                Node curr = q.poll();
                
                if(curr.CurrWord.equals(endWord)){
                    System.out.println(curr.path);
                    return curr.path;
                }
                for(Pair<String,Integer> neighbour : getNeighbour(visited,curr)) {
                    q.add(new Node
                }
            }
            
        }
        
    }
