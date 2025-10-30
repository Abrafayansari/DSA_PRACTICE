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


void inorder(Node *root,vector <int >*v){
	if(root==NULL){
		return;
	}
	
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
  
  Node * set(vector <int>*v){
  	Node *n1=new Node(v[0]);
  	n1->left=NULL;
  	for(int i=1;i<v.size()-1;i++){
  		Node *n=new Node(v[i]);
  		n->left=NULL;
  		n->right=
  		
	  
	  }
  }

int main(){
Node *root=new Node(3);
insert(root,4);
insert(root,2);
insert(root,8);
insert(root,5);



}
