#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder_traversal(struct node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    return;
}

void inorder_traversal(struct node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
    return;
}

void postorder_traversal(struct node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
    return;
}

int main(){

        //      1
        //    /  \
        //   2    3
        //  / \  / \
        // 4   5 6  7


    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
}
