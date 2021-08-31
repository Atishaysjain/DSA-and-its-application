#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

node* insert_at_root(node* root, int data){

    node* newnode = new node(data);
    newnode->next = root;
    if(root!=NULL){
        newnode->next->prev = newnode;
    }
    root = newnode;
    return root;

}


node* insert_at_tail(node* root, int data){
    
    
    if(root == NULL){
        root = insert_at_root(root, data);
        return root;
    }
    
    node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new node(data);
    temp->next->prev = temp;
    temp->next->next = NULL;

    return root;
}

void traverse(node* root){

    if(root == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return;
    }

    node* temp = root;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp<<endl;
    
    // traversing from behind
    if(root->next == NULL){
        cout<<root->data<<endl;
        return;
    }
    temp = root;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp->prev!=root){
        cout<<temp->data<<"<-";
        temp = temp->prev;
    }
    cout<<temp->data<<"<-"<<temp->prev->data<<endl;

    return;
}

node* insert_at_pos(node* root, int data, int pos){

    // root->1->2->3->4->6->NULL
    
    node* newnode = new node(data);

    if(pos == 1){
        root = insert_at_root(root, data);
        return root;
    }

    int count = 1;
    node* temp = root;
    while(pos != count && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp == NULL){
        cout<<"Position greater than length"<<endl;
        return root;
    }

    if(temp->next == NULL){
        root = insert_at_tail(root, data);
        return root;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    newnode->prev = temp;

    return root;
}



void delete_at_root(node** root){
    if(*root == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return;
    }
    node* root_main = *root;
    if(root_main->next == NULL){
        *root = NULL;
        return;
    }
    root_main->next = root_main->next->next;
    root_main->next->prev = *root;
    return;
}

void delete_at_tail(node* root){
    if(root == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return;
    }
    while(root->next->next != NULL){
        root = root->next;
    }
    // delete root->next;
    root->next->prev = NULL;
    root->next = NULL;
    return;
}

node* delete_at_pos(node* root, int pos){ // delete the element at the given position

    // root->1->2->3->4->5->NULL

    if(root == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return NULL;
    }
    int count = 1;
    node* temp = root;
    while(count != pos || temp == NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        cout<<"Position greater than the lenght of the list"<<endl;
        return root;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return root;

}

int main(){
    node* root = NULL;
    delete_at_root(&root); 
    root = insert_at_tail(root, 10);
    traverse(root);
    delete_at_root(&root);
    traverse(root);
    root = insert_at_tail(root, 10);
    traverse(root);
    root = insert_at_root(root, 2);
    root = insert_at_tail(root, 3);
    root = insert_at_tail(root, 4);
    root = insert_at_tail(root, 5);
    root = insert_at_tail(root, 6);
    root = insert_at_root(root, 1);
    traverse(root);
    delete_at_tail(root);
    traverse(root);
    delete_at_root(&root);
    root = delete_at_pos(root, 2);
    root = insert_at_pos(root, 10, 4);

    traverse(root);

    return 0;

}