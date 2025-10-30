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
return NULL;
}

Node *search(Node *root,int d ){
    if(root->data==d){
        return root;
    }
    if(root==NULL)return NULL;
   
    if(d<root->data){
        return search(root->left,d);
    }else{
        return search(root->right,d);
    }
}

Node* successor(Node* root){
    static bool go_right=true;
    if(root->left==NULL){
        return root;
    }
    if(go_right){
        successor(root->right);
        go_right=false;
    }else{
        successor(root->left);
    }
    
}


Node * delete_node(Node *root,int d){
   
   if(root==NULL)return root;
    if(root->data==d){
        //leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
     
        }
        //full node
        
      else if(root->left!=NULL&&root->right!=NULL){
          Node *n=successor(root);
            swap(n->data,root->data); 
            root->right=delete_node(root->right,n->data);
           return root;
        }
        //niether node
       else if(root->left==NULL&&root->right!=NULL){
       	Node *temp=root->right;
       	delete root;
       	return temp;
	   }
	   else if(root->left!=NULL&&root->right==NULL){
	   	Node *temp=root->left;
       	delete root;
       	return temp;
	   }
            
             
       
    }
   
    if(d<root->data){
         root->left=delete_node(root->left,d);
      
    }else{
        root->right=delete_node(root->right,d);

    }
   
    return root;
}

void inorder(Node *root){
if(root==NULL){
return;
}
inorder(root->left);
cout<<root->data<< " ";
inorder(root->right);

}
int main(){
Node *root=new Node(3);
insert(root,4);
insert(root,2);
inorder(root);
delete_node(root,3);
inorder(root);



}
