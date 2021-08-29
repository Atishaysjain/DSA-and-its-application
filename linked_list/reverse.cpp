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

    // root->1->2->NULL
    
    if(root == NULL){
        return NULL;
    }

    if(root->next == NULL){
        return root;
    }

    if(root->next->next == NULL){
        node* first = root->next;
        first->next = root;
        root->next = NULL;
        return first;
    }

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

node* reverse_next_k_nodes(node* root, int k){

    // root->1->2->3->4->5->NULL
    // root->2->1->4->3->5->NULL (for k == 2)
    // root->3->2->1->5->4->NULL (for k == 3)


    if(k == 0){
        cout<<"Value of k cannote be 0";
        return NULL;
    }

    if(k == 1){
        return root;
    }
    
    if(root == NULL){
        return NULL;
    }

    if(root->next == NULL){
        return root;
    }
    // reversing the first k nodes:- 

    // root->1->2->3
    node* first = root->next;
    node* second = root->next->next;
    root->next->next = root; // first->5->4<-root second->6->NULL (when recursion has been called for the second time)
    // root->1<-2<-f s->3->4
    int count = k-1;
    while(second != NULL && count > 1){
        if(second->next == NULL){
            second->next = first; // second->6->5->4<-root first->5->4<-root (when recursion has been called for the second time)
            root->next = NULL;
            return second;
        }
        else{
            node* temp = second->next;
            second->next = first;
            first = second; 
            second = temp; // root->1<-2<-3<-first temp->4<-second
        }
        count--;
        // root->1<-2<-3<-f s->4
    }

    root->next = reverse_next_k_nodes(second, k);

    // f->3->2->1->5->4->NULL

    return first;


}

void traverse(node* root){
    if(root == NULL){
        cout<<"NULL root recieved";
        return;
    }
    while(root->next != NULL){
        cout<<root->data<<"->";
        root = root->next;
    }
    cout<<root->data<<"->"<<root->next<<endl;
    return;
}

int main(){
    node* root = new node(1);
    root->next = new node(2);
    root->next->next = new node(3);
    root->next->next->next = new node(4);
    root->next->next->next->next = new node(5);
    root->next->next->next->next->next = new node(6);
    root->next->next->next->next->next->next = new node(7);
    root->next->next->next->next->next->next->next = new node(8);
    // root = reverse_linked_list(root);
    root = reverse_next_k_nodes(root, 2);
    traverse(root);
    return 0;
}

