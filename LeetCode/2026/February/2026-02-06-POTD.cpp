class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int ans = nums.size()-1;
        for(int i = 0; i<nums.size(); i++)
        {
            int st = i+1, en = nums.size()-1, ls = i;
            while(st <= en)
            {
                int mid = (st + en)/2;
                if(nums[mid] <= 1LL*nums[i]*k)
                {
                    ls = mid;
                    st = mid+1;
                }
                else
                {
                    en = mid-1;
                }
            }
            ans = min(ans,(int)(i+nums.size()-1-ls));
        }
        return ans;
    }
};