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

node* sum_replacement(node* root){


        //             1
        //         2       3
        //     4      5  6    7
        // 8     9      12       10
        //         11      13
        //                     14

    if(root == NULL){
        return 0;
    }

    int sum_lsb, sum_rsb;

    if(root->left == NULL){
        sum_lsb = 0;
    }else{
        sum_lsb = sum_replacement(root->left)->data; // sum of the left subtree of the given node
    }

    if(root->right == NULL){
        sum_rsb = 0;
    }else{
        sum_rsb = sum_replacement(root->right)->data; // sum of the right subtree of the given node
    }

    root->data = sum_lsb + sum_rsb + root->data; // replace the value in the node with the (sum of the left subtree + sum of the right sub tree + sum of the value in the node)
    
    return root;
}

int calc_height(node* root){

        //             1
        //         2       3
        //     4      5  6    7

    if(root == NULL){
        return 0;
    }
    return max(calc_height(root->left),calc_height(root->right)) + 1;
}

bool isBalanced(node* root){ // time complexity is O(n^2)
    if(root == NULL){
        return true;
    }
    int h_lsb = calc_height(root->left);
    int h_rsb = calc_height(root->right);
    if(abs(h_lsb - h_rsb) < 2){
        return true & isBalanced(root->left) & isBalanced(root->right);}
    return false;
}

bool optimizedIsBalanced(node* root, int* height){ // time complexity is O(n)
    
        //             1
        //         2       3
        //     4      5  6    7
    
    if(root == NULL){
        return true;
    }

    int h_lsb = 0;
    int h_rsb = 0;

    bool lsb_flag = optimizedIsBalanced(root->left, &h_lsb);
    bool rsb_flag = optimizedIsBalanced(root->right, &h_rsb);

    *height = max(h_lsb, h_rsb) + 1;

    if(abs(h_rsb-h_lsb)>=2){
        return false;
    }
    
    return lsb_flag && rsb_flag;


}

int main(){

        //             1
        //         2       3
        //     4      5  6    7
        // 8     9      12       10
        //         11      13
        //                     14

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->right->right->right = new node(10);
    root->left->left->right->right = new node(11);
    root->left->right->right = new node(12);
    root->left->right->right->right = new node(13);
    root->left->right->right->right->right = new node(14);

    root = sum_replacement(root);
    cout<<root->data<<endl;


        //      1
        //    /  \
        //   2    3
        //  / \  / \
        // 4   5 6  7


    struct node* new_root = new node(1);
    new_root->left = new node(2);
    new_root->right = new node(3);
    new_root->left->left = new node(4);
    new_root->left->right = new node(5);
    new_root->right->left = new node(6);
    new_root->right->right = new node(7);
    // new_root->right->right->right = new node(8);
    // new_root->right->right->right->left = new node(9);
    cout<<isBalanced(new_root)<<endl;
    int height = 0;
    cout<<optimizedIsBalanced(new_root, &height)<<endl;
    return 0;
}