#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DoubleDimensionalArray(){
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
}

void transpose(int arr[3][3], int n){
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[j][i] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } 
}

void matrixMultiplication(int a1[5][4], int a2[4][5]){
    
    int r1 = 5;
    int c1 = 4;
    int r2 = 4;
    int c2 = 5;
    
    int ans[r1][c2];

    // a1 = [[1,2,3],  a2 = [[1,2],
    //       [4,5,6]]        [3,4],
    //                       [5,6]] 

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int sum = 0;
            for(int k=0;k<c1;k++){
                sum += a1[i][k]*a2[k][j];
            }
            ans[i][j] = sum;
        }
    }

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 

          
}


void spiaralOrderTraversal(int arr[5][3], int n, int m){
    int i = 0, j = -1, loop = 1;
    int minimum = min(m, n);
    while(minimum+1-loop>=2){
        while(j<(m-loop)){
            j++;
            cout<<arr[i][j]<<"a ";
        }
        while(i<(n-loop)){
            i++;
            cout<<arr[i][j]<<"b ";
        }
        while(j>=loop){
            j--;
            cout<<arr[i][j]<<"c ";
        }
        while(i>=loop+1){
            i--;
            cout<<arr[i][j]<<"d ";
        }
        loop++;
        cout<<endl<<loop<<endl;
    }
}

bool double_Dimension_Sorted_Matrix_Search(int a[4][5], int b){
    // A sorted 2d matrix is given as input such that every row and column is sorted in ascending order. A number is given and we have to tell weather that number is present in the matrix or not

    int r = 4;
    int c = 5;

    // if the given value is greater than the value in the matrix then we move left else we move downwards. Either we could start from top right or we can start from bottom left

    int i = r-1;
    int j = 0;

    while(i>=0 && j<c){
        if(a[i][j] > b){ // move left because matrix element is greater than given value
            i--;
        }
        else if(a[i][j] < b){ // move downwards because matrix element is less than given value
            j++;
        }
        else return true;
    }

    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // DoubleDimensionalArray();
    // int arr[5][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    // spiaralOrderTraversal(arr, 5, 3);
    // int arr1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // transpose(arr1, 3);
    // int a1[5][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    // int a2[4][5] = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    // matrixMultiplication(a1, a2);
    // int a3[4][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    // cout<<double_Dimension_Sorted_Matrix_Search(a3, 9)<<endl;

    return 0;
}