class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) 
    {
        int ans = 0;
        int s = 1, e = 1e9;
        while(s <= e)
        {
            int mid = (s+e)/2;
            int cnt = 0;
            for(auto &i : arr) cnt += (i/mid + (i % mid != 0));
            if(cnt <= k)
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        return ans;
    }
};