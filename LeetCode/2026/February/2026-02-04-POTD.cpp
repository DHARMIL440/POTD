class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) 
    {
        int n = nums.size();
        vector <vector <long long>> dp(nums.size(),vector <long long>(3,-1e15));
        long long ans = LLONG_MIN;
        for(int i = 1; i<n; i++)
        {
            if(nums[i] > nums[i-1])
            {
                dp[i][0] = max(1LL*nums[i]+nums[i-1],nums[i]+dp[i-1][0]);
                if(i >= 3) dp[i][2] = nums[i] + max(dp[i-1][2],dp[i-1][1]);
            }
            else if(nums[i] < nums[i-1])
            {
                dp[i][1] = nums[i] + max(dp[i-1][0],dp[i-1][1]);
            }
            if(i >= 3) ans = max(ans,dp[i][2]);
        }
        return ans;
    }
};