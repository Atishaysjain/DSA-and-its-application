#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert_bst(node** root, int data){
    
    if(*root == NULL){
        *root = new node(data);
        return;
    }
    node* node_ptr = *root;
    if(data > node_ptr->data){
        insert_bst(&node_ptr->right, data);
    }
    else if(data < node_ptr->data){
        insert_bst(&node_ptr->left, data);
    }
    return;
}

node* create_bst(int arr[], int len){
    // int arr[] = {4,7,2,8,5,1,9,3};
    node* root = new node(arr[0]);
    for(int i=1;i<len;i++){
        insert_bst(&root, arr[i]);
    }
    return root;
}

void inorder_traversal(node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
    return;
}

int main(){

    int arr[] = {4,7,2,8,5,1,9,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    node* root = create_bst(arr, len);
    inorder_traversal(root);
    
    return 0;
}