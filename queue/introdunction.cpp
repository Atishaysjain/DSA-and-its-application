using namespace std;
#include<bits/stdc++.h>

// enqueue => insert
// dequeue => delete
// peek => tells the value at front
// empty => tells weather the queue is empty

// #define n 100
struct queue_{

    // array implementation of queue :-
    int n = 100;
    int* arr;
    int front;
    int back; // also called rear

    queue_(){
        arr = new int[n]; // Here arr is a pointer stored in stack part of the memory while the array itself will be stored in the heap part of the memory
        front = -1;
        back = -1;
    }
    // 1 2 3 4 5
    void dequeue(){
        if(back == -1){
            cout<<"Queue already empty"<<endl;
            return;
        }
        back--;
        if(back == -1){
            front = -1;
        }
        return;
    }
    void enqueue(int x){
        if(back == n-1){
            cout<<"Queue is full, no space to insert"<<endl;
            return;
        }
        back++;
        arr[back] = x;
        if(back == 0){
            front = 0;
        }
        return;
    }
    int peek(){
        if(front == -1){
            cout<<"queue is empty, no value to show"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){ // return true if empty, else will return false
        return (front==-1);
    }

};

void display(queue_ q){
    for(int i = 0;i<=q.back;i++){
        cout<<q.arr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
 
    // root -> 10 -> 12
    // node* root = new node(10);
    // root->next = new node(12);
    queue_ q;
    q.dequeue();
    q.enqueue(1);
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    display(q);

    return 0;
}
