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

int count_nodes(node* root){ // this would return the total number of nodes present in the tree

    if(root == NULL){
        return 0;
    }
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int return_sum(node* root){
    if(root == NULL){
        return 0;
    }
    return return_sum(root->left)+return_sum(root->right)+root->data;
}

int calculate_height(node* root){ // time complexity is O(n)

//             //      1
//             //   2     3  
//             // 4   5 6   7


    if(root == NULL){
        return 0;
    }
    return max(calculate_height(root->left), calculate_height(root->right)) + 1;
}

int calculate_diameter_method_1(node* root){ // time complexity of O(n^2)
    
    if(root == NULL){
        return 1;
    }

//             //      1
//             //   2     3  
//             // 4   5 6   7

    // if the current node is part of the diameter then the total path length would be (height of left sub tree + height of right sub tree), else it would be max(left sub tree diameter, right sub tree diamater)

    return max(calculate_height(root->left) + calculate_height(root->right) + 1, max(calculate_diameter_method_1(root->left), calculate_diameter_method_1(root->right)));
}

int calculate_diameter_method_2(node* root, int* height){ // time complexity is O(n)

//             //      1
//             //   2     3  
//             // 4   5 6   7

    if(root == NULL){
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;

    int ld = calculate_diameter_method_2(root->left, &lh);
    int rd = calculate_diameter_method_2(root->right, &rh);

    int currd = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(max(ld, rd), currd);
    
}

int main(){

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

     
        //             1
        //         2       3
        //     4      5  6    7
        // 8     9      12       10
        //         11      13
        //                     14

    cout<<count_nodes(root)<<endl; // this would return the total number of nodes present in the tree
    cout<<return_sum(root)<<endl; // this would return the summation of all the nodes of the binary tree
    cout<<calculate_height(root)<<endl; // this would return the height of the binary tree 
    cout<<calculate_diameter_method_1(root)<<endl; // calculated the longest path between 2 nodes of a binary tree
    int height = 0;
    cout<<calculate_diameter_method_2(root, &height)<<endl;
    return 0;
}