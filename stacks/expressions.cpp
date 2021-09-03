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

int postfix_evaluaton(string s){

    stack <int> st;
    int i = 0;
    cout<<s<<endl;
    while(i<s.length()){
        string element = "";
        bool is_operand = false;
        cout<<s[i]<<" ";
        cout<<endl;
        while(s[i] != ' '){
            cout<<s[i]<<" ";
            element += s[i];
            if(s[i]>= '0' && s[i]<= '9'){
                is_operand = true;
            }
            i++;
        }
        i++;
        // cout<<element;
        // if(i == s.length() - 1){
        //     break;
        // }else{i++;}
        // if(is_operand){
        //     int num = stoi(element);
        //     st.push(num);
        //     cout<<num<<endl;
        // }
        // else{
        //     int op1 = st.top();
        //     st.pop();
        //     int op2 = st.top();
        //     st.pop();
        //     switch(s[i]){
        //         case '+':
        //             st.push(op1+op2);
        //             break;
        //         case '-':
        //             st.push(op1-op2);
        //             break;
        //         case '*':
        //             st.push(op1*op2);
        //             break;
        //         case '/':
        //             st.push(op1/op2);
        //             break;
        //         default :
        //             break;
        //     }
        // }
    }
    // return st.top();
    return 0;
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

int main(){

    int arr[] = {1,2,3,4,5};
    stack<int> st;
    create_stack(st, arr, 5);
    // display(st);

    string postfix_expression = "1 2 * 3 + 5 4 10 / * -";
    // cout<<postfix_evaluaton(postfix_expression)<<endl;
    // postfix_evaluaton(postfix_expression);

    string prefix_expression = "-+*123*4/48";
    // string prefix_expression = "-+7*45+20";
    cout<<prefix_expression_evaluaton(prefix_expression)<<endl;

    // string a = "atishay";
    // string element = "";
    // cout<<element<<endl;
    // cout<<a[0]<<endl;
    // element += a[0];
    // element += a[1];
    // cout<<element<<endl;

    return 0;
}

// ((1*2)+3)-(5*(4/10)) = 3 => postfix expression => 1 2 * 3 + 5 4 10 / * -
// ((1*2)+3)-(4*(4/8)) = 3 => prefix expression => - + * 1 2 3 * 4 / 4 8