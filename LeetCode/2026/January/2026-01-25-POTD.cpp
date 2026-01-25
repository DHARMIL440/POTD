class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int start = 0, end = k-1;
        int ans = INT_MAX;
        while(end < nums.size())
        {
            ans = min(ans,nums[end]-nums[start]);
            start++;
            end++;
        }
        return ans;
    }
};