// Polycarp has found a table having an infinite number of rows and columns. The rows are numbered from 1, starting from the topmost one. The columns are numbered from 1, starting from the leftmost one.

// Initially, the table hasn't been filled and Polycarp wants to fix it. He writes integers from 1 and so on to the table as follows.

// The figure shows the placement of the numbers from 1 to 10. The following actions are denoted by the arrows.
// The leftmost topmost cell of the table is filled with the number 1. Then he writes in the table all positive integers beginning from 2 sequentially using the following algorithm.

// First, Polycarp selects the leftmost non-filled cell in the first row and fills it. Then, while the left neighbor of the last filled cell is filled, he goes down and fills the next cell. So he goes down until the last filled cell has a non-filled neighbor to the left (look at the vertical arrow going down in the figure above).

// After that, he fills the cells from the right to the left until he stops at the first column (look at the horizontal row in the figure above). Then Polycarp selects the leftmost non-filled cell in the first row, goes down, and so on.

// A friend of Polycarp has a favorite number k. He wants to know which cell will contain the number. Help him to find the indices of the row and the column, such that the intersection of the row and the column is the cell containing the number k.

// Input
// The first line contains one integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

// Each test case consists of one line containing one integer k (1≤k≤109) which location must be found.

// Output
// For each test case, output in a separate line two integers r and c (r,c≥1) separated by spaces — the indices of the row and the column containing the cell filled by the number k, respectively.

// Example
// inputCopy
// 7
// 11
// 14
// 5
// 4
// 1
// 2
// 1000000000
// outputCopy
// 2 4
// 4 3
// 1 3
// 2 1
// 1 1
// 1 2
// 31623 14130

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    // ith element of the 0th row would be i^2 + 1
    // jth element of the 0th column would be  (j+1)^2
    int n;
    cin>>n;
    int path = sqrt(n);
    if(path*path==n){
        path -= 1;
    }
    int mid_path = ((path*path+1)+((path+1)*(path+1)))/2;
    if(n == mid_path){
        cout<<path+1<<" "<<path+1<<endl;
        return;
    }
    else if(n > mid_path){
        cout<<path+1<<" "<<mid_path+path-n+1<<endl;
        return;
    }
    else{
        cout<<n-(path*path)<<" "<<path+1<<endl;
        return;
    }
} // path-(n-mid_path)+1

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}