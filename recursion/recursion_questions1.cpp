#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool checkArraySorted(int arr[], int n, int start_index){ // check weather the given array is strictly increasing
    if(start_index == n){
        return true;
    }
    else if(arr[start_index] < arr[start_index+1]){
        return true & checkArraySorted(arr, n, start_index+1);
    }
    return false;  
}

void firstAndLastOccurance(int arr[], int n, int a, int index, int direction){ // Output the first and the last element of an array
    if(arr[index] == a && !direction){
        cout<<index<<endl;
        firstAndLastOccurance(arr, n, a, n-1, 1);
    }
    else if(arr[index] == a && direction){
        cout<<index<<endl;
        return;
    }
    else if(!direction){
        firstAndLastOccurance(arr, n, a, index+1, 0);
    }
    else{
    firstAndLastOccurance(arr, n, a, index-1, 1);
    }
}

void reverse_string(string a){ // reverses a string using recursion
    if(a.length() == 0){
        return;
    }
    reverse_string(a.substr(1));
    cout<<a[0]<<" ";
    return;
}

string replace_pi_method2(string n){ // Replace all instances of 314 with pi in the given string using recursion
    if(n.length() < 3){
        cout<<n[0]<<n[1];
        return "";
    }
    if(n[0] == '3' && n[1] == '1' && n[2] == '4'){
        cout<<"pi";
        replace_pi_method2(n.substr(3));
    }
    else{
        cout<<n[0];
        replace_pi_method2(n.substr(1));
    }
    return "";
}

void replace_pi_method1(string n){ // Replace all instances of 314 with pi in the given string 
    if(n.find("314") >= n.size() || n.find("314") < 0){
        cout<<n<<endl;
        return;
    }
    int st = n.find("314");
    n[st] = 'p';
    n[st+1] = 'i';
    n.erase(st+2,1);
    replace_pi(n);
}

void tower_of_hanoi(int n, char from, char helper, char to){
    if(n == 0){
        return;
    }
    tower_of_hanoi(n-1, from, to, helper);
    cout<<"move"<<" "<<from<<" to "<<to<<endl;
    tower_of_hanoi(n-1, helper, from, to);
}


int main(){

    // int arr[5] = {13,2,3,4,5}; 
    // cout<<checkArraySorted(arr, 5, 0)<<endl;

    // int arr[10] = {1,2,3,4,1,6,1,8,1,6};
    // firstAndLastOccurance(arr, 10, 1, 0, 0);

    // string a = "atishay";
    // reverse_string(a);

    // cout<<replace_pi_method1("12314453146741389")<<endl;

    // replace_pi_method2("12314453146741389");

    // tower_of_hanoi(3, 'a', 'b', 'c');

    return 0;

}