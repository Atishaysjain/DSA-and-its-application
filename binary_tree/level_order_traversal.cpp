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

void k_order_traversal(node* root){ // print the the nodes in sequence of their
                    //      1
                    //   2     3  
                    // 4   5 6   7

        // output :- 1 2 3 4 5 6 7
    
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        if(q.front() != NULL){
            node* newnode = q.front();
            q.push(newnode->left);
            q.push(newnode->right);
            cout<<newnode->data<<" ";
            q.pop();
        }
        else if(q.front() == NULL){
            q.pop();
        }
    }
    return;
}

void sum_of_levels(node* root){
                    //      1
                    //   2     3  
                    // 4   5 6   7

        // output :- 1 5 22

    queue<node*> q;
    q.push(root);
    q.push(NULL); // NULL signifies end of a level
    int sum = 0;
    while(!q.empty()){
        if(q.front() == NULL && q.back() == NULL){
            cout<<sum<<" ";
            break;
        }
        if(q.front() == NULL){
            cout<<sum<<" ";
            sum = 0;
            q.pop();
            q.push(NULL);
        }
        else if(q.front() != NULL){
            node* newnode = q.front();
            sum += newnode->data;
            q.push(newnode->left);
            q.push(newnode->right);
            q.pop();
        }
        // cout<<"check "<<sum<<endl;
    }
    return;
}

int main(){

    // node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    // root->left->left->left = new node(8);
    // root->left->left->right = new node(9);
    // root->left->left->right->right = new node(11);
    // root->right->right->right = new node(10);

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    k_order_traversal(root);
    cout<<endl;
    sum_of_levels(root);
}