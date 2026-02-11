class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) 
    {
        int l = 0, h = *max_element(heights.begin(), heights.end());
        while (l < h) 
        {
            int m = l + (h - l) / 2;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); i++) 
            {
                c1 += (long long)abs(heights[i] - m) * cost[i];
                c2 += (long long)abs(heights[i] - m - 1) * cost[i];
            }
            c1 <= c2 ? h = m : l = m + 1;
        }
        long long ans = 0;
        for (int i = 0; i < heights.size(); ++i) ans += (long long)abs(heights[i] - l) * cost[i];
        return ans;
    }
};