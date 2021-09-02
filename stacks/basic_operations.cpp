#include<bits/stdc++.h>
using namespace std;

#define n 100

struct stack_{

    public:
    int top = -1;
    int arr[n];
    void push(int val){
        if(top == n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
        return;        
    }
    void pop(){
        if(top == -1){
            cout<<"Stack already empty"<<endl;
            return;
        }
        top--;
        return;
    }
    void get_top(){
        if(top == -1){
            cout<<"empty list"<<endl;
            return;
        }
        cout<<arr[top]<<endl;
        return;
    }
    bool is_empty(){
        return top==-1;
    }
};

int main(){

    stack_ st;
    st.get_top();
    st.pop();
    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.get_top();
    st.pop();
    st.get_top();
    st.pop();
    st.get_top();
    st.pop();
    st.get_top();
    st.pop();
    
    return 0;
}