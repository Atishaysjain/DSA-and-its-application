#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &arr) {
    int min_ = INT_MAX;
    int max_ = INT_MIN;
    for(int i=0;i<arr.size();i++){
        min_ = min(min_, arr[i]);
        max_ = max(max_, arr[i]);
    } 
    // |  
    // |  |     |
    // |  |     |
    // |  |  |  |
    int max_area = arr.size() * min_;
    int p1_index = 0;
    int h = min_+1;
    while(h<=max_){
        int curr_width = 0;
        int max_width = 0;
        int i = 0;
        bool consistency = false;
        while(i<=arr.size()){
            if(arr[i] >= h && !consistency){
                consistency = true;
                p1_index = i;
                curr_width = 1;
                max_width = max(max_width, curr_width);
            }
            else if(arr[i] >= h && consistency){
                if(i-p1_index == 1){
                    p1_index = i;
                    curr_width += 1;
                    max_width = max(max_width, curr_width);
                }
            }
            else{
                curr_width = 0;
                consistency = false;
            }
            i++;
        }
        max_area = max(max_area, (h*max_width));
        h++;
        p1_index = 0;
    }
    return max_area;
}

int main(){
    vector<int> arr = {95, 60, 99, 33, 92, 63, 35, 59, 12, 17, 92, 22, 79, 99, 39, 94, 30, 71, 86, 70, 77, 3, 55, 22, 100, 77, 97};
    int ans = largestRectangleArea(arr);
    cout<<ans<<endl;
    return 0;
}