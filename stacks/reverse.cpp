#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reverse_sentence(string s){

    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word = "";
        while(s[i] != ' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return;
}

// void insert_bottom(stack<int> *st, int t){

//     if(*st.empty()){
//         *st.push(t);
//         return;
//     }
//     int top_element = *st.top();
//     *st.pop();
//     insert_bottom(st, t);
//     *st.push(top_element);

//     return;
// }

// void reverse_stack_recursion(stack<int> *st){

//     // 5 4 3 2 1 -> 4 3 2 1 -> 3 2 1 -> 2 1 -> 1

//     if(*st.empty()){
//         return;
//     }

//     int t = *st.top();
//     *st.pop();
//     reverse_stack_recursion(st);
//     insert_bottom(st, t);
//     return;
    
// }

void insert_bottom(stack<int> &st, int t){

    if(st.empty()){
        st.push(t);
        return;
    }
    int top_element = st.top();
    st.pop();
    insert_bottom(st, t);
    st.push(top_element);

    return;
}

void reverse_stack_recursion(stack<int> &st){

    // 5 4 3 2 1 -> 4 3 2 1 -> 3 2 1 -> 2 1 -> 1

    if(st.empty()){
        return;
    }

    int t = st.top();
    st.pop();
    reverse_stack_recursion(st);
    insert_bottom(st, t);
    return;
    
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return;
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"Before reversing :- "<<endl;
    display(st);
    reverse_stack_recursion(st);
    cout<<"after reversing :- "<<endl;
    display(st);

    return 0;
}
