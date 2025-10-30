#include <iostream>
#include <vector>
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
return ;
}
inorder(root->left,v);
v->push_back(root->data);
inorder(root->right,v);
}

void find_sum(Node *root,vector <int>v,vector <int>*r,int target){
	int i=0;
	int j=v.size()-1;
	int sum=0;
	while(i<=j){
		sum=v[i]+v[j];
		if(sum<target){
			sum=sum-v[i];
			i++;
			
		}
		if(sum>target){
		sum=sum-v[j];

			j--;
			
		}
		if(sum==target){
			r->push_back(v[i]);
			r->push_back(v[j]);
			return ;
		}
	}
} 

  

int main(){
Node *root=new Node(3);
insert(root,4);
insert(root,2);
insert(root,6);
insert(root,1);
insert(root,7);
insert(root,30);
vector <int>v;
vector <int>r;

inorder(root,&v);
find_sum(root,v,&r,7);
cout<<r[0]<<" "<<r[1];



}
