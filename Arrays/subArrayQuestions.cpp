#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

void maximumSumSubArray(){ // This is better than brute force approach but worse than kadenes approach
    int i, j, n, maxSum = INT_MIN;
    cin>>n;
    int arr[n];
    int cumSum[n+1];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cumSum[0] = 0;
    cumSum[1] = arr[0];
    for(i=1;i<=n;i++){
        cumSum[i+1] = cumSum[i] + arr[i];
    }
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            maxSum = max(maxSum, cumSum[j] - cumSum[i]);
        }
    }
    cout<<maxSum<<endl;
}

void kadane(int arr[], int n)
{
    int maxEndings=arr[0];
    int res=maxEndings;
    for(int i=1 ; i<n ; i++)
    {
         maxEndings=max(arr[i], maxEndings+arr[i]);
         res=max(res, maxEndings);
    }
    cout<<res<<endl;
}

int kadaneReturn(int arr[], int n){
    int sum = arr[0];
    int result = arr[0];
    for(int i=1;i<n;i++){
        sum = max(arr[i], sum + arr[i]); 
        result = max(sum, result);
    } 
    return result;
}

void maximumCircularSubArraySum(int arr[], int n){ //  Here we also consider the possibility of a circular sub array
    int sum = kadaneReturn(arr, n);
    if(sum < 0){
        cout<<sum<<endl;
        return;
    }
    cout<<sum<<endl;
    int total_sum = 0;
    for(int i=0;i<n;i++){
        total_sum += arr[i];
        arr[i] = -arr[i];
    }
    int circular_sum = total_sum + kadaneReturn(arr, n);
    cout<<circular_sum<<endl;
    cout<<max(sum, circular_sum)<<endl;
}

bool pairSumBruteForce(int arr[], int n, int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool pairSum(int arr[], int n, int k){ // requieres a sorted array to work
// [1,2,3,4,5,6,7,8,9] (13)
    int low = 0;
    int high = n-1;
    while(low < high){
        if(arr[low] + arr[high] == k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low] + arr[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;

}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    // maximumSumSubArray();
    // int arr[] = {-4,-2,-6,-6,-10,-11,-12};
    // kadane(arr, 7);
    int arr1[] = {4,-4,6,-6,10,-11,12};
    // maximumCircularSubArraySum(arr1, 7);
    // cout<<pairSumBruteForce(arr1, 7, 22)<<endl;
    cout<<pairSum(arr1, 7, 22)<<endl;

    return 0;
}