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

int get_length(node* root){
    // root->1->2->3->NULL
    if(root == NULL){
        return 0;
    }
    int count = 0;
    while(root != NULL){
        root=root->next;
        count++;
    }
    return count;
}

int if_intersecting(node* r1, node* r2){

    // r1->1->2->3->4->5->6->7->8
    //       r2->3->4 / 

    int l1 = get_length(r1);
    int l2 = get_length(r2);
    int pos = -1; // -1 indicates that the two lists are not intersecting

    if(l2>l1){
        node* start = r2;
        int longer_start = l2-l1+1;
        int count = 1;
        while(count != longer_start){
            start = start->next;
            count++;
        }
        while(r1 != NULL){
            if(r1==start){
                pos = count;
                return pos;
            }
            r1 = r1->next;
            start = start->next;
            count++;
        }
        return pos;    
    }
    else if(l1>l2){
        node* start = r1;
        int longer_start = l1-l2+1;
        int count = 1;
        while(count != longer_start){
            start = start->next;
            count++;
        }
        while(r2 != NULL){
            if(r2==start){
                pos = count;
                return pos;
            }
            r2 = r2->next;
            start = start->next;
            count++;
        }
        return pos;    
    }
    return pos;
}



int main(){

    node* r1 = new node(1);
    r1->next = new node(2);
    r1->next->next = new node(3);
    r1->next->next->next = new node(4);
    r1->next->next->next->next = new node(5);
    r1->next->next->next->next->next = new node(6);
    r1->next->next->next->next->next->next = new node(7);
    r1->next->next->next->next->next->next->next = new node(8);

    node* r2 = new node(3);
    r2->next = new node(4);
    r2->next->next = r1->next->next->next->next;

    // r1->1->2->3->4->5->6->7->8
    //       r2->3->4 /

    cout<<if_intersecting(r1, r2)<<endl;

    return 0;
} 