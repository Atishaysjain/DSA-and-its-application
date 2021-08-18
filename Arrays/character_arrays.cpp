#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void palindrome_check(){
    int n;
    cin>>n;
    char arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // we could also have done arr[100]; cin>>arr;
    int i = 0;
    while(i!=n/2){
        if(arr[i] != arr[n-i-1])
        {
             cout<<"Not a palindrome"<<endl;
             break;
        }
        else i++;
    }
    if(i==n/2){
        cout<<"palindrome"<<endl;
    }
}

void max_length(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int max_length = 0;
    int word_number = 0;
    // cout<<arr[n]<<endl;
    while(arr[i] != '\0'){
        word_number += 1;
        int current_length = 0;
        while(arr[i] != ' ' && arr[i] != '\0'){
            current_length += 1;
            i++;
            cout<<i<<" "<<arr[i]<<" "<<word_number<<endl;
        }
        i++;
        // cout<<i<<" "<<arr[i]<<endl;
        max_length = max(max_length, current_length);
        current_length = 0;
    }
    cout<<max_length<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // char arr[100] = {'a', 'p', 'p', 'l', 'e'}; //  char arr[100] = "apple" // we can do like this also
    // int i = 0;
    // while(arr[i] != '\0'){
    //     cout<<arr[i]<<endl;
    //     i++;
    // }

    // palindrome_check();
    max_length();

    return 0;
}