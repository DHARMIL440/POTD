class Solution {
  public:
    int maxCircularSum(vector<int> &arr) 
    {
        int n = arr.size();
        int ans = INT_MIN, curr = 0, mx = INT_MIN;
        for(int i = 0; i<arr.size(); i++)
        {
            if(curr < 0) curr = 0;
            curr += arr[i];
            ans = max(ans,curr);
            mx = max(mx,arr[i]);
        }
        if(mx < 0)
        {
            return mx;
        }
        vector <int> back(n,0) , front(n,0);
        curr = 0, mx = 0;
        for(int i = 0; i<n; i++)
        {
            curr += arr[i];
            mx = max(mx,curr);
            front[i] = mx;
        }
        curr = 0, mx = 0;
        for(int i = n-1; i>=0; i--)
        {
            curr += arr[i];
            mx = max(mx,curr);
            back[i] = mx;
        }
        for(int i = 1; i<n; i++) ans = max(ans,front[i-1]+back[i]);
        return ans;
    }
};