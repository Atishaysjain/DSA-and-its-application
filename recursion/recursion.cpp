#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n == 0){
        return 0;
    }
    return n+sum(n-1);
}

int nRaisedToPowerP(int n, int p){
    if(p == 0){
        return 1;
    }else{
    return n*nRaisedToPowerP(n,p-1);}
}

int factorial(int n){
    if(n == 0){
    return 1; 
    }else{
    return n*factorial(n-1);}
}

int febonacci(int n){ // gives the nth febonacci number
    if(n == 0 || n == 1){
        return n;
    }
    return febonacci(n-1) + febonacci(n-2);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout<<sum(10)<<endl;
    cout<<nRaisedToPowerP(2, 10)<<endl;
    cout<<factorial(5)<<endl; 
    cout<<febonacci(10)<<endl;

    return 0;

}