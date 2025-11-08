#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int d) {
        data = d;
        left = right = NULL;
        height = 0;
    }
};

int maxi(int a, int b) {
    return (a > b) ? a : b;
}

int give_height(Node *root) {
    if (root == NULL) return -1;
    return 1 + maxi(give_height(root->left), give_height(root->right));
}

int bf(Node *root) {
    if (root == NULL) return 0;
    return give_height(root->left) - give_height(root->right);
}

Node* right_rotate(Node *root) {
    Node *x = root->left;
    Node *temp = x->right;
    x->right = root;
    root->left = temp;
    root->height = give_height(root);
    x->height = give_height(x);
    return x;
}

Node* left_rotate(Node *root) {
    Node *x = root->right;
    Node *temp = x->left;
    x->left = root;
    root->right = temp;
    root->height = give_height(root);
    x->height = give_height(x);
    return x;
}

Node* minValueNode(Node* root) {
    Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* insert(Node *root, int d) {
    if (root == NULL)
        return new Node(d);

    if (d < root->data)
        root->left = insert(root->left, d);
    else if (d > root->data)
        root->right = insert(root->right, d);
    else
        return root;

    root->height = give_height(root);
    int b = bf(root);

    if (b < -1) {
        if (d > root->right->data)
            return left_rotate(root);
        else {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    if (b > 1) {
        if (d < root->left->data)
            return right_rotate(root);
        else {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }

    return root;
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

Node* deleteNode(Node* root, int d) {
    if (root == NULL) return root;

    if (d < root->data)
        root->left = deleteNode(root->left, d);
    else if (d > root->data)
        root->right = deleteNode(root->right, d);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = (root->left) ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = successor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL) return root;

     root->height = give_height(root);
    int b = bf(root);

    if (b < -1) {
        if (d > root->right->data)
            return left_rotate(root);
        else {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }

    if (b > 1) {
        if (d < root->left->data)
            return right_rotate(root);
        else {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
    }

    return root;
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Before Deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 40);
    root = deleteNode(root, 25);

    cout << "After Deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}


