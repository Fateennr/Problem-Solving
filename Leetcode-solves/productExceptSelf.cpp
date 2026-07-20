#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1);

        prefix[0] = nums[0];
        postfix[nums.size()-1] = nums[nums.size()-1];


        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] * nums[i];
            // cout << prefix[i] << " ";
        }
        // cout << "\n";

        for(int i=nums.size()-2;i>=0;i--){
            postfix[i] = postfix[i+1] * nums[i];
            // cout << postfix[i] << " ";
        }
        // cout << "\n";

        // for(auto c: postfix){
        //     cout << c << " ";
        // }
        // cout << "\n";

        //         for(auto c: prefix){
        //     cout << c << " ";
        // }
        // cout << "\n";

        vector<int> result(nums.size());

        result[0] = postfix[1];
        result[nums.size()-1] = prefix[nums.size()-2];

        
        for(int i=1;i<nums.size()-1;i++){
            // cout << postfix[i+1] << " " << prefix[i-1] << "\n";
            result[i] = prefix[i-1] * postfix[i+1];
        }

        return result;
    }
};


int main(){
    Solution s;

    vector<int> nums = {1,2,4,6};

    vector<int> result = s.productExceptSelf(nums);

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
