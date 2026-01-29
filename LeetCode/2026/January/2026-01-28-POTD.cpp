class Solution {
public:

    void reduce(vector <int> &prev)
    {
        for(int i = 1; i<prev.size(); i++) prev[i] = min(prev[i],prev[i-1]);
        return;
    }
    int minCost(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size(), m = grid[0].size();
        
        vector <int> prev(1e4+1,INT_MAX);
        vector <vector <int>> dp(n,vector <int>(m,0));

        for(int i = n-1; i>=0; i--)
        {
            for(int j = m-1; j>=0; j--)
            {
                if(i != n-1 || j != m-1)
                {
                    int ans1 = INT_MAX, ans2 = INT_MAX;
                    if(i+1 < n) ans1 = dp[i+1][j] + grid[i+1][j];
                    if(j+1 < m) ans2 = dp[i][j+1] + grid[i][j+1];
                    dp[i][j] = min(ans1,ans2);
                }
                prev[grid[i][j]] = min(prev[grid[i][j]],dp[i][j]);
            }
        }
        
        reduce(prev);

        for(int kk = 0; kk<k; kk++)
        {
            vector <int> tmp(1e4+1,INT_MAX);
            for(int i = n-1; i>=0; i--)
            {
                for(int j = m-1; j>=0; j--)
                {
                    if(i != n-1 || j != m-1)
                    {
                        int ans1 = INT_MAX, ans2 = INT_MAX, ans3;
                        if(i+1 < n) ans1 = dp[i+1][j] + grid[i+1][j];
                        if(j+1 < m) ans2 = dp[i][j+1] + grid[i][j+1];
                        ans3 = prev[grid[i][j]];
                        dp[i][j] = min({ans1,ans2,ans3});
                    }
                    tmp[grid[i][j]] = min(tmp[grid[i][j]],dp[i][j]);
                }
            }
            prev = tmp;
            reduce(prev);
        }

        return dp[0][0];

    }
};