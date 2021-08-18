#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n){
    if(n > 0){
        return !(n & n-1);
    }
    else if(n == 0){
        return true; 
    }
}

int numberOfOnesInBinary(int n){
    int ans = 0;
    while (n != 0){
        n = n & n-1;
        ans += 1;
    }
    return ans;
}

// how do you get bits? => n & n-1
// {a,b,c,d} => {1,0,1,1} & {0,0,0,1}
void allPossibleSets(int arr[], int n){
    for(int i=0;i<(1<<n);i++){ // 1<<n represents 2^n in binary
        for(int j=0;j<n;j++){ // looping to find at which position of i is one present.
            if(1<<j & i){ // If i is present at that p
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int uniqueNumber(int arr[], int n){
    // {1,2,3,2,1} => 3
    int xorsum = 0; 
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    } 
    return xorsum;
}

void doubleUniqueNumber(int arr[], int n){
    int xorsum = 0; 
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    } // xorsum => a ^ b => n => 110101 ; n-1 => 110100
    int setPos = 0, i = 0;
    while(true){
        if(xorsum&(1<<i)){
            break;
        }
        else{
            setPos++;
        }
        i++;
    }    
    int xorsumNew = 0;
    for(i=0;i<n;i++){
        if(1<<setPos & arr[i]){
            xorsumNew = xorsumNew^arr[i];
        }
    }

    // xorsumNew is now the first unique number
    int secondUniqueNumber = xorsumNew^xorsum;
    cout<<xorsumNew<<" "<<secondUniqueNumber<<endl;
    return;
}

void tripleUniqueNumber(int arr[], int n){ // Find the 3 unique numbers in an array in which all the other numbers are repeated once 
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    }
    for(int i=0;i<n;i++){
        int xorsumSecond = xorsum^arr[i];  
        for(int j=i+1;j<n;j++){
            if(j!=i){
                int xorsumThird = xorsumSecond^arr[j];
                for(int k=0;k<n;k++){
                if(k!=j){
                    int xorsumFourth = xorsumThird^arr[k];
                    if(xorsumFourth == 0){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    return;
                    }
                }
            }
            }
        }
    }   
}

bool getBit(int n, int pos){
    return ((n&(1<<pos)) != 0);
}

int setBit(int n, int pos){
    return (n|(1<<pos));
}

void threeDouplicateNumbers(int arr[], int n){ // Find the unique number in an array where repeated numbers are repeated thrice and only one number is present once. 

    int result = 0;

    for(int i=0;i<64;i++){ 
        int count = 0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j], i)){
                count++;
            }
        }
        if(count%3 != 0){
            result = setBit(result, i);
        }
    }
    cout<<result<<endl;
}

int main(){ 
    // Keep in mind the following things :- 
    // to get n-1 from n :- flip all the digits from the right most set(1) bit of n including the rightmost set bit
    // Example :- n => 8(1000) ; n-1 = 7(0111) {we flipped all bits after 1 in 8 because it was the rightmost bit. Same would be the case with n=5(0101) and n-1=4(0100)} 

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // cout<<isPowerOf2(64)<<endl;
    // cout<<numberOfOnesInBinary(7)<<endl;
    // int arr[4] = {1,2,3,4};
    // allPossibleSets(arr, 4);
    // int arr[] = {1,4,5,3,7,5,4,3,1};
    // cout<<uniqueNumber(arr,9)<<endl;
    // int arr[] = {1,11,12,1,45,11,34,11,12,1,1,34};
    // doubleUniqueNumber(arr, 12);
    // int arr[] = {1,11,12,1,45,11,34,11,12,1,1,34,212};
    // tripleUniqueNumber(arr, 13);
    int arr[] = {1,2,3,4,3,5,4,3,1,2,1,2,4};
    threeDouplicateNumbers(arr,13);
    return 0;

}