#include <iostream>
using namespace std;

class Node{
public:
int data;
Node *right;
Node *left;

Node(int d){
data=d;
left=right=NULL;
}
};

Node* create(int d){
return new Node(d);
}

Node* insert(Node *root,int d){
if(root==NULL){
return create(d);
}
if(d<root->data){
root->left=insert(root->left,d);
}else{
root->right=insert(root->right,d);
}
return root;
}

  void smallest(Node *root,int &count,int n){
  	
  	if(root==NULL)return;
  	
  	smallest(root->left,count,n);
  	count++;
  	if(n==count){
  	cout<<root->data;
	  return;	
	  } 
	    	smallest(root->right,count,n);

	   }

int main(){
Node *root=new Node(3);
insert(root,4);
insert(root,2);
insert(root,5);
insert(root,7);
int count=0;
smallest(root,count,3);


}
