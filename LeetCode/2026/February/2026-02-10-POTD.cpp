class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            map <int,int> even, odd;
            for(int j = i; j<nums.size(); j++)
            {
                if(nums[j]&1) odd[nums[j]] = 1;
                else even[nums[j]] = 1;
                if(even.size() == odd.size()) ans = max(ans,j-i+1);
            }
        }    
        return ans;
    }
};