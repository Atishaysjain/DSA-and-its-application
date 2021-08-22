#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void increment(int *ptr){
    *ptr += 1; 
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // Simple pointer
    int *ptr;
    int a = 10;
    ptr = &a; 
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    // Array pointer
    int arr[] = {1,2,3,4};
    cout<<arr<<endl;
    cout<<*arr<<endl;
    cout<<*(arr+1)<<endl; // Indexing pointer

    // Pointer to pointer
    a = 10;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    
    cout<<a<<" "<<*ptr1<<" "<<**ptr2<<endl;
    cout<<&a<<" "<<ptr1<<" "<<*ptr2<<endl;

    // Pointer implementation
    a = 10;
    int *p = &a;
    increment(p);
    cout<<a<<endl;

    // Heaps
    a = 10;
    int *pointer = new int(); // The pointer would be stored in a stack but it is pointing towards a memory location in heap
    *pointer = 10;
    // cout<<pointer<" "<<*pointer<<endl;
    delete(pointer); // deallocate memory

    int *pntr = new int(10); 
    
    pointer = new int[4];
    cout<<pointer<<endl;
    delete[]p;
    p = NULL;

    return 0;
}