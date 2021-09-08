// Problem link :- https://www.interviewbit.com/old/problems/maxspprod/

// Problem Description

// You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
// Write a program to find the maximum special product of any integer in the array.

// NOTE: As the answer can be large, output your answer modulo 109 + 7.



// Problem Constraints
// 1 <= N <= 105
// 1 <= A[i] <= 109



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return an integer denoting the maximum special product of any integer.



// Example Input
// Input 1:

//  A = [1, 4, 3, 4]
// Input 2:

//  A = [10, 7, 100]


// Example Output
// Output 1:

//  3
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
//  So, the ans is 1*3 = 3.
 
// Explanation 2:

//  There is not any integer having maximum special product > 0. So, the ans is 0.

// Soultion Approach :- 

// Ok, lets try to calculate LeftSpecialValue.

// Lets make a stack A.
// We will keep elements in strictly decreasing order in stack A.

// When processing the ith element remove all the elements from the stack which have value less than or equal to ith element.
// Now whatever element will remain at the top of index will give the index corresponding to LeftSpecialValue. If no element is at top then take it as 0.

// Push ith element in stack A now.

// You can see each element is pushed and popped for atmax one time. Hence the solution runs in O(n) time.

// Do the similar thing for RightSpecialValue.


#include<bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> &arr) {
    
    int mod = 1e+9 + 7;
    vector<int> leftv = {0};
    stack<int> st;
    st.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }
        if(st.empty()){leftv.push_back(0);}
        else{leftv.push_back(st.top());}
        st.push(i);
    }
    // 1, 4, 3, 4  
    // 1 4 
    stack<int> st_;
    st_.push(arr.size()-1);
    vector<int> rightv = {0};
    for(int i=arr.size()-2;i>=0;i--){
        while(!st_.empty() && arr[i] >= arr[st_.top()]){
            st_.pop();
        }
        if(st_.empty()){rightv.push_back(0);}
        else{rightv.push_back(st_.top());}
        st_.push(i);
    }

    reverse(rightv.begin(), rightv.end());
    int max_product = INT_MIN;
    for(int i = 0;i<rightv.size();i++){
        max_product = max(max_product, leftv[i] * rightv[i]);
        // cout<<arr[i]<<" "<<leftv[i]<<" "<<rightv[i]<<" "<<leftv[i] * rightv[i]<<" "<<max_product<<endl;
    }
    return max_product%mod;
}

int main(){
    vector<int> v = {7, 5, 7, 9, 8, 7};
    cout<<maxSpecialProduct(v)<<endl;

}