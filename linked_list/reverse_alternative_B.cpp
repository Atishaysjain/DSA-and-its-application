// Given a linked list A of length N and an integer B.

// You need to reverse every alternate B nodes in the linked list A.



// Problem Constraints
// 1 <= N <= 105
// 1<= Value in Each Link List Node <= 103
// 1 <= B <= N
// N is divisible by B


// Input Format
// First argument is the head pointer of the linkedlist A.

// Second argument is an integer B.



// Output Format
// Return the head pointer of the final linkedlist as described.



// Example Input
// Input 1:

//  A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
//  B = 3
//  Input 2:

//  A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
//  B = 2


// Example Output
// Output 1:

//  7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
// Output 2:

//  4 -> 1 -> 6 -> 6 -> 10 -> 4


// Example Explanation
// Explanation 1:

//  The linked list contains 9 nodes and we need to reverse alternate 3 nodes.
//  First sublist of length 3  is 3 -> 4 -> 7 so on reversing it we get 7 -> 4 -> 3.
//  Second sublist of length 3 is 5 -> 6 -> 6 we don't need to reverse it.
//  Third sublist of length 3 is 15 -> 61 -> 16 so on reversing it we get 16 -> 61 -> 15.
// Explanation 2:

//  The linked list contains 6 nodes and we need to reverse alternate 2 nodes.
//  First sublist of length 2 is 1 -> 4 so on reversing it we get 4 -> 1.
//  Second sublist of length 2 is 6 -> 6 we don't need to reverse it.
//  Third sublist of length 2 is 4 -> 10 so on reversing it we get 10 -> 4.


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

ListNode* reverse(ListNode* root, int n){

    // root->1->2->3->4->5->6->x
    if(root->next->next == NULL){
        root->next->next = root;
        ListNode* temp = root->next;
        root->next = NULL;
        return temp;
    }
    if(n == 2){
        ListNode* temp = root->next->next;
        root->next->next = root;
        ListNode* first = root->next;
        root->next = temp;
        return first;
    }
    ListNode* first;
    ListNode* second;
    first = root->next;
    second = root->next->next;
    root->next->next = root;
    int count = 1;
    while(count<n-2){
        ListNode* temp = second->next;
        second->next = first;
        first = second;
        second = temp;
        count++;
    }
    root->next = second->next;
    second->next = first;
    return second;
    
} 


ListNode* solve(ListNode* A, int B) {

// A->3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
// A->7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15

    if(B==1){
        return A;
    }

    ListNode* temp = A;
    bool if_reverse = true;
    int count = 1;
    while(temp != NULL){
        if(if_reverse){
            if(temp == A){ // 
                ListNode* new_temp = temp;
                ListNode* reversed_list = reverse(new_temp, B);  
                A = reversed_list;
                // cout<<temp->val<<" ";
                temp=temp->next;
                // cout<<temp->val<<" ";
                if_reverse = false;
            }
            else{ 
            ListNode* new_temp = temp;
            temp = temp->next;
            ListNode* reversed_list = reverse(temp, B); 
            new_temp->next = reversed_list;
            // cout<<temp->val<<" ";
            temp = temp->next; 
            // cout<<temp<<" ";
            if_reverse = false;
            }
        }
        else{
            // cout<<"hello";
            count = 1; // 
            // cout<<temp->val<<" ";
            while(count<B){ // 
                temp = temp->next;
                count++;
            }
            if_reverse = true; // 
            // cout<<temp->val<<" ";
            if(temp->next == NULL){
                return A;
            }
        }
    }
    return A;
}

void traverse(ListNode* root){

    if(root == NULL){
        cout<<"NULL pointer recieved"<<endl;
        return;
    }
    while(root->next != NULL){
        cout<<root->val<<"->";
        root = root->next;
    }
    cout<<root->val<<endl;
    return;
}

int main(){

    ListNode* A = new ListNode(1);
    A->next = new ListNode(2);
    A->next->next = new ListNode(3);
    A->next->next->next = new ListNode(4);
    A->next->next->next->next = new ListNode(5);
    A->next->next->next->next->next = new ListNode(6);
    // A->next->next->next->next->next->next = new ListNode(7);
    // A->next->next->next->next->next->next->next = new ListNode(8);
    // A->next->next->next->next->next->next->next->next = new ListNode(9);
    cout<<endl;
    ListNode* root = solve(A, 3);
    traverse(root);
    return 0;
}