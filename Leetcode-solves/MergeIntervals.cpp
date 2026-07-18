#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> & b){
            return a[0] < b[0];
        });


        for(int i=1; i<intervals.size();i++){
            int prev_start = intervals[i-1][0];
            int prev_end = intervals[i-1][1];
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if(prev_end >= curr_start){
                intervals[i][0] = prev_start;
                intervals[i][1] = max(prev_end, curr_end);
                intervals.erase(intervals.begin() + i-1);
                i--;
            }
        }

        return intervals;
    }
};


int main() {
    // Write C++ code here
    
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = s.merge(intervals);

    for(int i=0;i<ans.size();i++){
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]\n";
    }

    return 0;
}