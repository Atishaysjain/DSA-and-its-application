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

void right_view(node* root){ // The idea is to print the righmost node of each level. Thus we will do level order traversal.

    //         1
    //     2       3
    // 4        5     6
    //        7     8

    // 1 NULL 2 3 NULL 4 5 6 NULL 7 8 NULL

    if(root == NULL){
        cout<<"please provide a valid root pointer"<<endl;
        return;
    }
    
    vector <node*> v;
    v.push_back(root);
    v.push_back(NULL);
    int start = 0; // index of the first element of the vector
    int end = 1; // index of the last element of the vector
    while(!v.empty()){
        if(v.at(start) == NULL && v.at(end) == NULL){
            break;
        }
        if(v.at(start) == NULL){
            v.push_back(NULL);
            end++;
            start ++; // equivalent to popping the first element
        }
        else if(v.at(start) != NULL){
            node* newnode = v.at(start);
            if(newnode->left != NULL){
                v.push_back(newnode->left);
                end++;
            }
            if(newnode->right != NULL){
                v.push_back(newnode->right);
                end++;
            }
            if(v.at(start+1) == NULL){
                cout<<v.at(start)->data<<" ";
            }
            start ++;
        }
    }

    return;
}

void right_view_queue(node* root){

    if(root == NULL){
        cout<<"please provide a valid root pointer"<<endl;
        return;
    }

    //         1
    //     2       3
    // 4        5     6
    //        7

    queue <node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n-1;i++){
            node* newnode = q.front();
            if(newnode->left != NULL){
                q.push(newnode->left);
            }
            if(newnode->right != NULL){
                q.push(newnode->right);
            }
            q.pop();
        }
        cout<<q.front()->data<<" ";
        node* newnode = q.front();
        if(newnode->left != NULL){
            q.push(newnode->left);
        }
        if(newnode->right != NULL){
            q.push(newnode->right);
        }
        q.pop();
    } 
    return;   
}

void left_view_queue(node* root){ // print the leftmost element of each level

    if(root == NULL){
        cout<<"please provide a valid root pointer"<<endl;
        return;
    }

    queue <node*> q;
    q.push(root);
    while(!q.empty()){
        node* newnode = q.front();
        cout<<newnode->data<<" ";
        int n = q.size();
        for(int i=0;i<n;i++){
            if(newnode->left != NULL){
                q.push(newnode->left);
            }
            if(newnode->right != NULL){
                q.push(newnode->right);
            }
            q.pop();
        }
    }
    return;
}

int main(){
    
    //         1
    //     2       3
    // 4        5     6
    //        7

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    // root->right->right->left = new node(8);

    right_view(root); // outputs the right view of the binary tree using vector
    cout<<"\n";
    right_view_queue(root); // outputs the right view of the binary tree using queue
    // left_view(root); // outputs the left view of the binary tree using queue
    cout<<"\n";
    left_view_queue(root);

    return 0;
}