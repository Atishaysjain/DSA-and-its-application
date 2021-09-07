// Question link :- https://www.interviewbit.com/problems/sliding-window-maximum/

// Given an array of integers A.  There is a sliding window of size B which 

// is moving from the very left of the array to the very right. 

// You can only see the w numbers in the window. Each time the sliding window moves 

// rightwards by one position. You have to find the maximum for each window. 

// The following example will give you more clarity.

// The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

// Window position	Max
// ———————————-	————————-
// [1  3  -1] -3  5  3  6  7	3
// 1 [3  -1  -3] 5  3  6  7	3
// 1  3 [-1  -3  5] 3  6  7	5
// 1  3  -1 [-3  5  3] 6  7	5
// 1  3  -1  -3 [5  3  6] 7	6
// 1  3  -1  -3  5 [3  6  7]	7
// Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

// Note: If B > length of the array, return 1 element with the max of the array.




// Input Format

// The first argument given is the integer array A.
// The second argument given is the integer B.
// Output Format

// Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]
// For Example

// Input 1:
//     A = [1, 3, -1, -3, 5, 3, 6, 7]
//     B = 3
// Output 1:
//     C = [3, 3, 5, 5, 6, 7]

// Approach :- 
// The double-ended queue is the perfect data structure for this problem. It supports insertion/deletion from the front and back. The trick is to find a way such that the largest element in the window would always appear in the front of the queue. How would you maintain this requirement as you push and pop elements in and out of the queue?

// You might notice that there are some redundant elements in the queue that we shouldn’t even consider about. For example, if the current queue has the elements: [10 5 3], and a new element in the window has the element 11. Now, we could have emptied the queue without considering elements 10, 5, and 3, and insert only element 11 into the queue.

// A natural way most people would think is to try to maintain the queue size the same as the window’s size. Try to break away from this thought and try to think outside of the box. Removing redundant elements and storing only elements that need to be considered in the queue is the key to achieve the efficient O(n) solution.


vector<int> Solution::slidingMaximum(const vector<int> &arr, int b) {


    // [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
    
    // Input 1:
    // A = [1, 3, -1, -3, 5, 3, 6, 7]
    // B = 3
    // Output 1:
    // C = [3, 3, 5, 5, 6, 7]

    deque<int> dq; // this will store the indices of the elements of the input array
    vector<int> result;
    if(b >= arr.size()){
        int max_ = INT_MIN;
        for(int i=0;i<arr.size();i++){
            max_ = max(arr[i], max_);
        }
        result.push_back(max_);
        return result;
    }
    for(int i=0;i<arr.size();i++){
        if(!dq.empty() && dq.front() == i-b){dq.pop_front();}
        while(!dq.empty()  &&  arr[i] >= arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(i>=b-1) result.push_back(arr[dq.front()]);
    }
    
    return result;
}
