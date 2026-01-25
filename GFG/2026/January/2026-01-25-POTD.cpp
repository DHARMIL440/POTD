class Solution {
  public:
  
    int solve(int open, int close, int max_allowed)
    {
        int ans = 0;
        if(open == close && open == max_allowed) return 1;
        if(open + 1 <= max_allowed) ans += solve(open+1,close,max_allowed);
        if(close < open) ans += solve(open,close+1,max_allowed);
        return ans;
    }
    
    int findWays(int n) 
    {
        if(n&1) return 0;
        return solve(0,0,n/2);
    }
};