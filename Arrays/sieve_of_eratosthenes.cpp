#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sievePrime(int n){
    int arr[100];
    for(int i=0;i<100;i++){
        arr[i] = 0;
    }
    for(int i=2;i<n;i++){
        if(arr[i] == 0){
            for(int j=i*i;j<n;j+=i){
                arr[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cout<<i<<" ";
        }
    }
    return;
}

void sievePrimeFactorization(int n){
    cout<<"Hello!";
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            for(int j=i*i;j<n;j+=i){
                arr[j] = i;
            }
        }
    }
    while(arr[n] != 0){
        // cout<<arr[n]<<endl;
        cout<<arr[n]<<" ";
        n = arr[n];
    }
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    cout<<"Hello!";
    // sievePrime(80);
    sievePrimeFactorization(80);
    return 0;
}