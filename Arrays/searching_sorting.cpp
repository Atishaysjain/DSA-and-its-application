#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

void binarySearch(){ 
    int i, n, a, mid, start, end;
    cin>>n;
    int arr[n];
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }
    cin>>a;
    start = 0;
    end = n-1;
    mid = (start + end) / 2;

    while(start != end){
        if (arr[mid] > a){
            end = mid - 1;
        } 
        else if (arr[mid] < a){
            start = mid + 1;
        }
        else{
            break;
        }
        mid = (start + end) / 2;
    }
    if (arr[mid] == a){
        cout<<a;
    }
    else {
        cout<<"Not found";
    }
}

void bubbleSort(){
    // Repeatedly sort adjecant arrays if in wrong order
    int i, n, j, temp;
    cin>>n;
    int arr[n];
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }    
    for(i = 1;i < n;i++){
        for(j = 0;j < n-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (i = 0;i < n;i++){
        cout<<arr[i]<<endl;
    }
}


void sort(){ 
    int i, n, j, temp;
    cin>>n;
    int arr[n];
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }    
    for(i = 0;i < n;i++){
        for(j = i+1;j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (i = 0;i < n;i++){
        cout<<arr[i]<<endl;
    }    
}

void insertionSort(){ // [5,3,4,1,2]
    // take an element from an unsorted array and place it in it's correct position of sorted array
    int i, n, j, current;
    cin>>n;
    int arr[n];
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }    
    for(i = 0;i <= n;i++){ // Sorting the array till the current element
        current = arr[i];
        j = i - 1;
        while(arr[j]>current && j >= 0){ 
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    for (i = 0;i < n;i++){
        cout<<arr[i]<<endl;
    }
}

int32_t main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // binarySearch();
    // sort();
    // bubbleSort();
    insertionSort();
    return 0;
    
}
