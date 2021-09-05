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

struct queue_{
    node* front;
    node* back;
    
    queue_(){
        front = NULL;
        back = NULL;
    }

    void enqueue(int x){
        if(back == NULL){
            back = new node(x);
            front = back;
            return;
        }
        back->next = new node(x);
        back = back->next;
        return;
    }

    void dequeue(){
        if(back == NULL){
            cout<<"The queue is already empty"<<endl;
            return;
        }
        if(front == back){
            delete(front);
            delete(back);
            back = NULL;
            front = NULL;
            return;
        }
        // 1->2->NULL
        delete(front);
        front = front->next;
        // node* temp = front;
        // while(temp->next->next != NULL){
        //     temp = temp->next;
        // }
        // delete(back);
        // back = temp;
        // back->next = NULL;
        return;
    }

    int peek(){
        if(front == NULL){
            cout<<"Queue is empty, nothing to show"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        return front == NULL;
    }
};

int main(){

    queue_ q;
    q.dequeue(); 
    q.enqueue(0);
    q.enqueue(1);
    cout<<q.peek()<<endl;
    q.enqueue(3);
    q.dequeue();
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.peek()<<endl;


    return 0;
}