// Question link :- https://www.interviewbit.com/problems/rain-water-trapped/

// Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



// Problem Constraints
// 1 <= |A| <= 100000



// Input Format
// The only argument given is integer array A.



// Output Format
// Return the total water it is able to trap after raining.



// Example Input
// Input 1:

//  A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
// Input 2:

//  A = [1, 2]


// Example Output
// Output 1:

//  6
// Output 2:

//  0


// Example Explanation
// Explanation 1:

 
//  In this case, 6 units of rain water (blue section) are being trapped.
// Explanation 2:

//  No water is trapped.

#include<bits/stdc++.h>
using namespace std;

int trap(const vector<int> &arr) { 
    int total = 0;
    int h = 1;
    int n = arr.size();
    int p1_index; 
    bool p1 = false, p2 = false;
    while(true){
        for(int i=0;i<n;i++){
            if(p1 == false && arr[i] >= h){
                p1 = true;
                p1_index = i; 
                p2 = true;
            }   
            else if(p1 == true && arr[i] >= h){
                if(i - p1_index >= 2){ // water can be trapped
                    total += i-p1_index-1;
                    p1_index = i;
                }
                else{
                    p1_index = i;
                }
            }
        }
        p1 = false;
        if(p2 == false){return total;}
        p2 = false;
        h++;
    }  
    return total;
}


int main(){
    vector<int> v;
    v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trap(v)<<endl;

    return 0;
}