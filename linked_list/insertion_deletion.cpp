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

void insertAtTail(node* head, int val){ 
    while(head->next != NULL){
        head = head->next;
    }
    node* newnode = new node(val);
    head->next = newnode; 
    return;
}

void insertAtHead(node** head, int val){
    node* newnode = new node(val);
    newnode->next = *head;
    *head = newnode;
    return;
}

void insertAtPositon(node *head, int pos, int val){ // insert at a given position(index+1)
    node* newnode = new node(val);
    for(int i=0;i<pos-1;i++){
        if(head != NULL){
            head = head->next;
        }
        else{
            cout<<"Went beyond the lenght of linked list"<<endl;
            return;
        }
    }
    newnode->next = head->next;
    head->next = newnode;
    return;
}

void deleteAtTail(node *head){
    while(head->next->next != NULL){
        head = head->next;
    }
    head->next = NULL;
    return;
}

void deleteAtHead(node** head){
    node* test = *head;
    node* temp = test->next;
    *head = temp;
    return;
}

// void deleteFromAPosition(node **head, int pos){ // Not working
//     if(pos<2){ // we have to delete the first element
//         *head = NULL;
//         return;
//     }
//     node** temp = head;
//     for(int i=0;i<pos-2;i++){
//         if(*temp != NULL){
//             node* test = *temp;
//             *temp = test->next;
//         }
//         else{
//             cout<<"Went beyond the lenght of linked list"<<endl;
//             return;
//         }
//     }
//     node* test = temp->next;
//     temp->next = test->next;
//     return;

// }

void traverse(node* head){
    while(head != NULL){
        cout<<"->"<<head->data;
        head = head -> next;
    }
    cout<<endl;
    return;
}

void append_k(node** head, int pos){ // takes the last k nodes and appends them at the beginning

    // head->1->2->3->4->5->NULL
    if(*head == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return;
    }

    node* temp = *head;
    if(temp->next == NULL){
        return;
    }

    int count = 1;
    node* addr_prev;
    while(temp->next != NULL){
        if(count == pos){
            addr_prev = temp;
        }
        temp = temp->next;
        count += 1;
    }
    temp->next = *head;
    *head = addr_prev->next;
    addr_prev->next = NULL;

    return;

}
int main(){

    node* head = new node(1); // head ponter pointing towards the first node
    insertAtTail(head, 3); // 2 will be inserted after 1
    insertAtTail(head, 4);
    insertAtHead(&head, 0); // 0 will be inserted as the first node
    insertAtPositon(head, 2, 2);
    traverse(head);
    deleteAtTail(head);
    deleteAtHead(&head);
    traverse(head);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    append_k(&head, 3); // takes the last k nodes and appends them at the beginning
    traverse(head);

    return 0;
}