#include<bits/stdc++.h>
using namespace std;

struct stack_{ // when push operation is made costly
    queue<int> q1;
    queue<int> q2;

    void push(int val){
        if(q1.empty()){
            q1.push(val);
            return;
        }
        q2.push(val);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return;
    }

    void pop(){
        if(q1.empty()){
            cout<<"Already empty"<<endl;
            return;
        }
        q1.pop();
        return;
    }

    int top(){
        if(q1.empty()){
            cout<<"Already empty"<<endl;
            return -1;
        }
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

// struct stack__{
//     queue<int> q1;
//     queue<int> q2;


// };

int main(){

    stack_ st;
    cout<<st.empty()<<endl;
    st.push(1);
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    st.push(2);
    cout<<st.top()<<endl;
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    return 0;
}