#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

node* reverse_linked_list(node* root){

    // root->1->2->3->4->NULL
    // NULL<-1<-2<-3<-4<-ROOT

    node* first = root->next;
    node* second = root->next->next;
    root->next->next = root;
    root->next = NULL;
    while(second->next != NULL){
        node* temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }
    second->next = first;
    root = second;

    return root;
}

void traverse(node* root){
    if(root == NULL){
        cout<<"NULL root recieved";
        return;
    }
    while(root->next != 0){
        cout<<root->data<<"->";
        root = root->next;
    }
    cout<<root->data<<endl;
    return;
}

int main(){
    node* root = new node(1);
    root->next = new node(2);
    root->next->next = new node(3);
    root->next->next->next = new node(4);
    root = reverse_linked_list(root);
    traverse(root);
    return 0;
}

