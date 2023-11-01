#include <bits/stdc++.h>

using namespace std;
int dp[205][20005];

bool solve(int ind, vector<int> &nums, int sum);

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // cout<<sum<<endl;
    memset(dp, -1, sizeof(dp));
    // cout<<sum<<endl;
    if (sum % 2)
    {
        return false;
    }
    return solve(nums.size() - 1, nums, sum / 2);
    // return 1;
}

bool solve(int ind, vector<int> &nums, int sum)
{
    // cout<<"gg"<<endl;
    if (sum == 0)
    {
        return true;
    }

    if(ind<0 ){return false;}

    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }

    bool ans = solve(ind - 1, nums, sum);

    if (sum - nums[ind] >= 0)
    {
        ans |= solve(ind - 1, nums, sum - nums[ind]);
    }

    return dp[ind][sum] = ans;
}

int main()
{
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << endl;

    return 0;
}