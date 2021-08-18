// Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.



// Problem Constraints
// 1 <= N <= 103.

// 1 <= B <= N 

// -102 <= A[i][j] <= 102.



// Input Format
// First arguement is an 2D integer matrix A.

// Second argument is an integer B.



// Output Format
// Return a single integer denoting the maximum sum of submatrix of size B x B.



// Example Input
// Input 1:

//  A = [
//         [1, 1, 1, 1, 1]
//         [2, 2, 2, 2, 2]
//         [3, 8, 6, 7, 3]
//         [4, 4, 4, 4, 4]
//         [5, 5, 5, 5, 5]
//      ]
//  B = 3
// Input 2:

//  A = [
//         [2, 2]
//         [2, 2]
//     ]
//  B = 2


// Example Output
// Output 1:

//  48
// Output 2:

//  8


// Example Explanation
// Explanation 1:

//     Maximum sum 3 x 3 matrix is
//     8 6 7
//     4 4 4
//     5 5 5
//     Sum = 48
// Explanation 2:

//  Maximum sum 2 x 2 matrix is
//   2 2
//   2 2
  Sum = 8
  
  int Solution::solve(vector<vector<int> > &A, int B) {

    int n = A.size();
    
    int rowsum[n][n-B+1];
    int sum[n-B+1];
    for(int i=0;i<n-B+1;i++){
        sum[i] = 0;
    }
    int result = INT_MIN;
    
    for(int i = 0;i<n;i++){ // traversing across rows
        rowsum[i][0] = 0;
        for(int j=0;j<B;j++){ // traversing across first B columns
            rowsum[i][0] += A[i][j];   
        }
        sum[0] += rowsum[i][0];
        if(i>=B-1){
            result = max(result, sum[0]);
            sum[0] -= rowsum[i-B+1][0];
        }
        for(int j=1;j<n-B+1;j++){ // traversing across columns
            rowsum[i][j] = rowsum[i][j-1] + A[i][j+B-1] - A[i][j-1];
            sum[j] += rowsum[i][j];
            if(i>=B-1){
                result = max(result, sum[j]);
                sum[j] -= rowsum[i-B+1][j];
            }
        }
    }
    
    return result;
}
