class Solution 
{
public:
    int minimumCost(vector<int>& nums) 
    {
        int ans = INT_MAX, mn = nums[nums.size()-1];
        for(int i = nums.size()-2; i>0; i--)
        {
            ans = min(ans,nums[i]+mn);
            mn = min(mn,nums[i]);
        }     
        return ans + nums[0];
    }
};