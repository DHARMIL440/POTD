class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        vector <int> res;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] >= 0)
            {
                int pnt = (i + nums[i]) % n;
                res.push_back(nums[pnt]);
            }
            else
            {
                int pnt = ( (i - abs(nums[i]))%n + n) % n;
                res.push_back(nums[pnt]);
            }
        }    
        return res;
    }
};