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

node* lca(node* root, int n1, int n2){ // If for a node, n1 is present in   the left sub tree and n2 is present in the right sub tree or vice versa then that node would be the lca for n1 and n2

    //         1
    //     2       3
    // 4        5      6
    //        7   8

    if(root == NULL){
        return NULL;
    }
    
    if(root->data == n1 | root->data == n2){
        return root;
    }

    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }

    if(left != NULL){
        return left;
    }

    if(right != NULL){
        return right;
    }

    if(left == NULL && right == NULL){
        return NULL;
    }

    return NULL;

}

int dist_nodes(node *root, int n){

    //         1
    //     2       3
    // 4        5      6
    //        7   8

    if(root == NULL){
        return -1;
    }

    if(root->left != NULL){
        if(root->left->data == n){
            return 1;
        }
    }

    if(root->right != NULL){
        if(root->right->data == n){
            return 1;
        }
    }

    int ld = dist_nodes(root->left, n);
    int rd = dist_nodes(root->right, n);

    if(ld != -1){
        return ld + 1;
    }

    if(rd != -1){
        return rd + 1;
    }

    return -1;

}
int shortest_distance(node* root, int n1, int n2){
    
    node* least_common_ancestor = lca(root, n1, n2);
    
    int d1 = dist_nodes(least_common_ancestor, n1);
    int d2 = dist_nodes(least_common_ancestor, n2);

    return d1+d2;
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

    cout<<shortest_distance(root, 4, 7)<<endl; // returns the shortest distance between two nodes

    return 0;
}