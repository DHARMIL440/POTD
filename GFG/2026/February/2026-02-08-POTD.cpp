class Solution {
  public:
    int maxProduct(vector<int> &arr) 
    {
        int ans = INT_MIN, mn = INT_MIN, pr = 1;
        for(auto &i : arr)
        {
            if(i == 0)
            {
                mn = INT_MIN;
                pr = 1;
                ans = max(ans,i);
            }
            else
            {
                pr *= i;
                ans = max(ans,pr);
                if(mn != INT_MIN) ans = max(ans,pr/mn);
                if(pr < 0) mn = max(mn,pr);
            }
        }
        return ans;
    }
};