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


Node * LCA(Node *root,Node *a,Node *b){
	
	if(root==NULL)return NULL;
	if(root->data>a->data&&root->data>b->data){
		return LCA(root->left,a,b);
	}
	if(root->data<a->data&&root->data<b->data){
		return LCA(root->right,a,b);
	}
	return root;
}
  

int main(){
Node *root=new Node(3);
insert(root,4);
insert(root,2);

int count=0;
Node *n=LCA(root,insert(root,7),insert(root,5));
cout<<n->data;

}
