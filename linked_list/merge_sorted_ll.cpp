#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void traverse(node* root){

    if(root == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return;
    }
    while(root->next != NULL){
        cout<<root->data<<"->";
        root = root->next;
    }
    cout<<root->data<<"->"<<root->next<<endl;
    return;
}

node* merge_sorted(node* r1, node* r2){

    // r1->1->6->9->12->13->35->36
    // r2->1->2->3->10->15->16->23->29

    if(r1 == NULL && r2 == NULL){
        cout<<"Both pointers are NULL";
        return NULL;
    }
    node* root = new node(-1);
    node* temp = root;
    bool first_node = true;
    while(r1 != NULL && r2 != NULL){
        if(r1->data >= r2->data){
            if(first_node){
                root->next = r2;
                first_node = false;
                r2 = r2->next;
                temp = temp->next;
            }
            else{
                temp->next = r2;
                r2 = r2->next;
                temp = temp->next;
            }
        }
        else{
            if(first_node){
                root->next = r1;
                first_node = false;
                // temp->next = r1;
                r1 = r1->next;
                temp = temp->next;
            }
            else{
                temp->next = r1;
                r1 = r1->next;
                temp = temp->next;
            }
        }
    } 
    if(r1 == NULL){
        while(r2 != NULL){
            temp->next = r2;
            r2 = r2->next;
        }
    }
    else{
        while(r1 != NULL){
            temp->next = r1;
            r1 = r1->next;
        }
    }
    return root->next;
}

node* merge_sorted_recursion(node* r1, node* r2){

    // r1->1->1->6->9->12->13->35->36
    // r2->1->2->3->10->15->16->23->29

    if(r1==NULL){
        return r2;
    }
    if(r2 == NULL){
        return r1;
    }
    node* root = new node(-1);
    node* temp = root;
    if(r1->data >= r2->data){
        temp->next = r2;
        temp = temp->next;
        temp->next = merge_sorted_recursion(r1, r2->next);
    }
    else{
        temp->next = r1;
        temp = temp->next;
        temp->next = merge_sorted_recursion(r1->next, r2);
    }
    return root->next;

}

int main(){

    node* r1 = new node(1);
    r1->next = new node(6);
    r1->next->next = new node(9);
    r1->next->next->next = new node(12);
    r1->next->next->next->next = new node(13);
    r1->next->next->next->next->next = new node(35);
    r1->next->next->next->next->next->next = new node(36);

    node* r2 = new node(1);
    r2->next = new node(2);
    r2->next->next = new node(3);
    r2->next->next->next = new node(10);
    r2->next->next->next->next = new node(15);
    r2->next->next->next->next->next = new node(16);
    r2->next->next->next->next->next->next = new node(23);
    r2->next->next->next->next->next->next->next = new node(29);

    // node* root = merge_sorted(r1, r2); // merges two sorted linked list so that it gives us a combined sorted linked list. Note that we are not making a new linked list but rather combining the given two linked list.
    node* root = merge_sorted_recursion(r1, r2); // Doing the same process through recursion

    traverse(root);

    return 0;
} 
