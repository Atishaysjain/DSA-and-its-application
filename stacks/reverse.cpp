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

int main(){
    stack<int> st;
    string s = "Hey, How are you brother?";
    reverse_sentence(s);
}
