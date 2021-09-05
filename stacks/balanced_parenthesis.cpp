#include<bits/stdc++.h>
using namespace std;
#include<stack>
#define ll long long int

// char get_opposite_bracket(char a){
//     if(a == ')'){return '(';}
//     if(a == '('){return ')';}
//     if(a == ']'){return '[';}
//     if(a == '['){return ']';}
//     if(a == '}'){return '{';}
//     if(a == '{'){return '}';}
//     return ' ';
// }

// bool if_balanced(string s){
//     stack<char> st;
//     for(int i=0;i<s.length()/2;i++){
//         st.push(s[i]);
//     }
//     for(int i=s.length()/2;i<s.length();i++){
//         char a = get_opposite_bracket(st.top());
//         if(a != s[i]){
//             // cout<<s[i]<<" "<<st.top()<<endl;
//             return false;
//         }
//         else{
//             // cout<<s[i]<<" "<<st.top()<<endl;
//             st.pop();
//         }
//     }
//     return true;
// }

char get_opposite_bracket(char a){
    if(a == ')'){return '(';}
    if(a == '('){return ')';}
    if(a == ']'){return '[';}
    if(a == '['){return ']';}
    if(a == '}'){return '{';}
    if(a == '{'){return '}';}
    return ' ';
}

bool is_opening(char a){
    if(a == '(' || a == '{' || a == '['){
        return true;
    }
    return false;
}

bool is_ending(char a){
    if(a == ')' || a == '}' || a == ']'){
        return true;
    }
    return false;
}
bool is_balanced(string s){
    stack<char> open;
    for(int i=0;i<s.length();i++){
        if(is_opening(s[i])){
            open.push(s[i]);
        }
        else if(is_ending(s[i])){
            if(get_opposite_bracket(s[i]) == open.top()){
                open.pop();
            }
            else{return false;}
        }
    }
    return true;
}


void solve(string s)
{
    cout<<s<<" "<<is_balanced(s)<<endl;
}

int main()
{
    // Sample Input :- 
    // 5
    // {{[({[)]}}
    // {{}}()[]([])
    // {{}}()[]([])
    // (A+B)-{a-3{2-[4]}}
    // (A+B)-{a-3{2-[4}}

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
    }
    return 0;
}