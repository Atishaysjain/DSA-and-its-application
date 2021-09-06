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
        if(front == NULL){
            cout<<"The queue is already empty"<<endl;
            return;
        }
        if(front == back){
            delete front;
            delete back;
            back = NULL;
            front = NULL;
            return;
        }
        node* to_delete =  front;
        front = front->next;
        delete to_delete;
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
    cout<<q.peek()<<endl;
    q.enqueue(0);
    cout<<q.peek()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;

    return 0;
}