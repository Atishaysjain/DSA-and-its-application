#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){ // Tells weather the bit at the given position is 1 or not
    return ((n & (1<<pos))!= 0); // 1<<pos is a left shift operator. So 1<<3 is 1000, 1 is shifted to the 3rd position
}

int setBit(int n, int pos){ // Sets the bit at the given position to 1
    return (n | (1<<pos));
}

int clearBit(int n, int pos){ // clears the bit at the given position
    int mask = ~(1<<pos); // ~ => gives us the one's complement
    return(n & mask);
}

int updateBit(int n, int pos, int updateVal){
    int mask = ~(1<<pos);
    n = mask & n;
    return (n | updateVal<<pos);
}
 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout<<getBit(7,2)<<endl;
    cout<<setBit(5,3)<<endl;
    cout<<clearBit(5,2)<<endl;
    cout<<updateBit(5,1,1)<<endl;

}