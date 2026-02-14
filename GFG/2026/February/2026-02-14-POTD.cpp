class Solution {
  public:
    int minTime(vector<int>& arr, int k) 
    {
        int ans = 0, s = 1, e = 1e9;
        while(s <= e)
        {
            int mid = (s+e)/2;
            int sum = 0, cnt = 1;
            bool ch = 1;
            for(int &i : arr)
            {
                if(i > mid) ch = 0;
                else if(sum + i <= mid) sum += i;
                else sum = i, cnt++;
            }
            if(ch && cnt <= k)
            {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};