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

node* search_bst(node* root, int val){
    if(root == NULL){
        cout<<"The given element is not present"<<endl;
        return NULL;
    }
    if(root->data > val){
        return search_bst(root->left, val);
    }
    else if(root->data < val){
        return search_bst(root->right, val);
    }
    else if(root->data == val){
        return root;
    }

    return NULL;

}

// vector<int> return_inorder(node* root){
//     vector<int> inorder;
//     while()
// }

void delete_in_bst(node** root_ptr, int val){

    //          10
    //       5       15
    //     3   7   13   20
    //   1            17

    node* root = *root_ptr;
    if(root == NULL){
        cout<<"The element is not present in the tree"<<endl;
        return;
    }
    if(root->data > val){
        delete_in_bst(&root->left, val);
    }
    else if(root->data < val){
        delete_in_bst(&root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root; // TODO
            return;
            
        }
        if(root->left == NULL | root->right == NULL){
            if(root->left != NULL){
                node* temp = root->left;
                root->data = root->left->data;
                root->left = root->left->left;
                root->right = root->left->right;
                delete temp;
                return;
            }
            if(root->right != NULL){
                node* temp = root->right;
                root->data = root->right->data;
                root->left = root->right->left;
                root->right = root->right->right;
                delete temp;
                return;
            }
            node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            delete temp;
            return;
        }  
    }
    return;
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

void level_order_traversal(node* root){

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        if(q.front() != NULL){
            cout<<q.front()->data<<" ";
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
        else q.pop();
    }

}

int main(){

    //          10
    //       5       15
    //     3   7   13   20
    //   1            17

    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(3);
    root->left->right = new node(7);
    root->right->left = new node(13);
    root->right->right = new node(20);
    root->right->right->left = new node(17);
    root->left->left->left = new node(1);

    node* data_ptr = search_bst(root, 1); // data_ptr would point towards the given data
    if(data_ptr != NULL){
        cout<<data_ptr->data<<endl;
    }
    cout<<endl;
    cout<<"Before deleting data :- "<<endl;
    inorder_traversal(root);
    cout<<endl<<endl;
    cout<<"After deleting data :- "<<endl;
    delete_in_bst(&root, 17); // root will point towards the new bst with deleted node
    inorder_traversal(root);

    return 0;
}