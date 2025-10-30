#include <iostream>
#include <climits>
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

bool validate(Node* root, int min , int max ) {
    if (root == NULL) return true;
if(root->data<max&&root->data>min){
	bool left =validate(root->left,min,root->data);
	bool right =validate(root->right,root->data,max);
	return right&&left;
	
}
else return false;
}

int main(){
Node *root=new Node(3);
insert(root,4);
insert(root,2);
insert(root,9);
insert(root,5);
if(validate(root,INT_MIN,INT_MAX))cout<<"yes";
else cout<<"no";




}
