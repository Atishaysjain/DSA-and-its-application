#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// number of subarrays of an array with n elements :- nC2 + n = n*(n+1)/2
// number of subsequences = 2^n
// every subsequence is an subarray but not every subarray is a subsequence

void sumOfSubArrays(){ // Finds the sum of all sub arrays of an array 
    int i,j,k,n;
    cin>>n;
    int arr[n];
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }
    int sum = 0;
    int sumSubArray = 0;
    for(i = 0;i < n;i++){
        for(j = i;j < n;j++){
            sumSubArray = 0;
            for(k = i;k <= j;k++){
                sumSubArray += arr[k];
            }
            // cout<<sumSubArray<<endl;
            sum += sumSubArray;
        }
    }
    cout<<sum;
}

void maximumArithmeticSubArrayLenght(){ // Finds the maximum length of sub array in the array which has the same differnce between it's consecutive elements

    int i, n, pd, curr, ans;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    pd = arr[1] - arr[0];
    curr = 2;
    ans = 2;
    i = 2;
    while(i<n){
        if(pd == arr[i] - arr[i-1]){
            curr += 1;
            ans = max(ans, curr);
        }
        else{
            pd = arr[i] - arr[i-1];
            curr = 2;
        }
        i++;
    }
    cout<<ans;
}

void recordBreakingDay(){
    int i, n_days = 0, n, max_visitors;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    max_visitors = arr[0];
    for(i=1;i<n-1;i++){
        if(arr[i] > max_visitors && arr[i] > arr[i+1]){
            max_visitors = arr[i];
            n_days += 1;}
    }
    cout<<n_days;
}

void minIndexRepeating(){
    int i, n, minIndex = INT_MAX;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    const int N = 1e6 + 2;
    int idx[N];
    for(i=0;i<N;i++){
        idx[i] = -1;
    }
    for(i=0;i<n;i++){
        if(idx[arr[i]] == -1){
            idx[arr[i]] = i;
        }
        else{
            minIndex = min(minIndex, idx[arr[i]]);
        }
    }
    if (minIndex ==INT_MAX){cout<<"-1";}
    else{cout<<minIndex+1;}
}

void subArrayWithGivenSum(){ // Given a sum find the starting and last index of the sub array which has it's sum equal to the given sum.
    int i = 0, n, sum = 0, inputSum, minIndex = 0, maxIndex = 0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>inputSum;
    while(minIndex < n && maxIndex < n){
        while(sum <= inputSum){
            sum += arr[maxIndex];
            maxIndex++;
            cout<<maxIndex<<" First while loop"<<endl;
        }
        maxIndex--;
        if(sum == inputSum){
            cout<<"starting index :- "<<minIndex<<endl;
            cout<<"last index :- "<<maxIndex<<endl;
            return;
        }
        while(sum >= inputSum){
            sum -= arr[minIndex];
            minIndex++;
            cout<<minIndex<<" "<<maxIndex<<" Second while loop"<<endl;
            if(sum == inputSum){
                cout<<"starting index :- "<<minIndex<<endl;
                cout<<"last index :- "<<maxIndex<<endl;
                return;
        }
        }
    }
}

void minimumPositiveInteger(){
    int i, n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int const N = 1e+6 + 1;
    bool flag[N];
    for(i=0;i<n;i++){
        if(arr[i] >= 0){
            flag[arr[i]] = true;}
    }
    i=0;
    while(flag[i] != false){
        i++;
    }
    cout<<i<<endl;
    return;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // sumOfSubArrays();
    // maximumArithmeticSubArrayLenght();
    // recordBreakingDay();
    // minIndexRepeating();
    // subArrayWithGivenSum();
    // minimumPositiveInteger();
    return 0;
}