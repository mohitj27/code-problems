class node {
	constructor(data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
}

let root ; 

function insertLevelOrder(arr,i){
	  let root = null;
	  if(arr[i] == null){
	  	return null;
	  }
	  if(i < arr.length){
      
	  root = new node(arr[i]);

	  root.left = insertLevelOrder(arr,2*i + 1);

	  root.right = insertLevelOrder(arr,2*i + 2);
     

	  }
	  return root;
} 
function inOrder(root){
	if(root!= null){
		inOrder(root.left);
		console.log(root.data + " ");
		inOrder(root.right);
	}
}
let arr = ["foo","bar","boo","c","baz","fiz","a","b",null,null,"boo","c","buzz",null];u
let arr = [1,2,3,4,5,6,6,6,6];
root = insertLevelOrder(arr,0);
inOrder(root);
