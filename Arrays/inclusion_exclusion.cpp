#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void divisible(int n, int a, int b){ // Outputs total number of times n is seperately divided by a and b
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    cout<<c1+c2-c3<<endl;
    return;
}

void gcd(int x, int y){ // Outputs the greatest common divisor of x and y
    int a = max(x,y);
    int b = min(x,y);
    while(b!=0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    cout<<a<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    divisible(35,5,7);
    gcd(32,48);

    return 0;

}
