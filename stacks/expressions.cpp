#include<bits/stdc++.h>
#include<stack>
#include<math.h>
using namespace std;

// infix operatons :- operand operation operand :- 2 + 3
// prefix operation(polish notation) :- operator operand operand :- 5-6/3 => - 5 / 6 3
// postfix operation(reverse polich notation) :- operand operand operator :- 5-6/3 => 5 6 3 / -

void create_stack(stack <int> &st, int arr[], int n){
    for(int i=0;i<n;i++){
        st.push(arr[i]);
    }
    return;
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    return;
}

int prefix_expression_evaluaton(string s){

    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i] - '0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}

int precedence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '^'){
        return 3;
    }
    return -1;
}

string infix_to_postfix(string infix_expression){

// 1*2+3-4*4/(8-4) => ((1*2)+3)-(4*(4/(8-4))) => 1 2 * 3 + 4 4 8 4 - / * -
    stack <char> st;
    string result = ""; 
    for(int i=0;i<infix_expression.length();i++){
        if(infix_expression[i] > '0' && infix_expression[i] < '9'){
            result += infix_expression[i];
        }
        else if(infix_expression[i] == ')'){
            while(st.top() != '(' && !st.empty()){
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else if(infix_expression[i] == '('){
            st.push(infix_expression[i]);
        }
        else{
            if(!st.empty()){
                while(precedence(st.top()) >= precedence(infix_expression[i]) && !st.empty()){
                    result += st.top();
                    st.pop();
                    if(st.empty()){
                        break;  
                    }
                }
                st.push(infix_expression[i]);
            }
            else{
                st.push(infix_expression[i]);
            }
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

void reverse_and_change_brackets(string &s){
    for(int i =0;i<(s.length())/2;i++){
        char temp = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = temp;
        if(s[i] == ')'){
            s[i] = '(';
        }
        else if(s[i] == '('){
            s[i] = ')';
        }
        if(s[s.length() - 1 - i] == ')'){
            s[s.length() - 1 - i] = '(';
        }
        else if(s[s.length() - 1 - i] == ')'){
            s[s.length() - 1 - i] = '(';
        }
    }
}

string infix_to_prefix(string s){
    // ((1*2)+3)-(4*(4/8)) = 3 => prefix expression => - + * 1 2 3 * 4 / 4 8

    // First reverse the string
    // Then swap '(' whith ')' and vice verse
    // Then apply infix_to_posfix
    // Then reverse the Ouptut string


    reverse_and_change_brackets(s);

    string result = infix_to_postfix(s);

    reverse_and_change_brackets(result);

     
    return result;

}

int main(){

    int arr[] = {1,2,3,4,5};
    stack<int> st;
    create_stack(st, arr, 5);                       
    // display(st);

    string prefix_expression = "-+*123*4/48";
    cout<<"Prefix expression evaluated :- "<<prefix_expression_evaluaton(prefix_expression)<<endl;

    string infix_expression = "1*2+3-4*4/(8-4)";
    cout<<"infix_expression :- "<<infix_expression<<endl;
    string postfix_converted = infix_to_postfix(infix_expression);
    cout<<"Converted Postfix Expression :- "<<postfix_converted<<endl;

    string prefix_converted = infix_to_prefix(infix_expression);
    cout<<"Converted Prefix Expression :- "<<prefix_converted<<endl;
    return 0;
}

// ((1*2)+3)-(5*(4/10)) = 3 => postfix expression => 1 2 * 3 + 5 4 10 / * -
// ((1*2)+3)-(4*(4/8)) = 3 => prefix expression => - + * 1 2 3 * 4 / 4 8