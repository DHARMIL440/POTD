class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        int minDiff = INT_MAX;
        vector<int> ans(3);

        while (i < a.size() && j < b.size() && k < c.size()) 
        {
            int mn = min({a[i], b[j], c[k]});
            int mx = max({a[i], b[j], c[k]});

            if (mx - mn < minDiff) 
            {
                minDiff = mx - mn;
                ans = {a[i], b[j], c[k]};
            }

            if (mn == a[i]) i++;
            else if (mn == b[j]) j++;
            else k++;
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
