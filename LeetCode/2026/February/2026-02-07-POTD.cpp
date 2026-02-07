class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n = s.size();
        vector <int> fb(n,0), fa(n,0);
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i] == 'b') cnt++;
            fb[i] = cnt;
        }
        cnt = 0;
        int ans = INT_MAX;
        for(int i = n-1; i>=0; i--)
        {
            if(s[i] == 'a') cnt++;
            fa[i] = cnt;
        }
        for(int i = 0; i+1<n; i++) ans = min(ans,fb[i]+fa[i+1]);
        ans = min({ans,fb[n-1],fa[0]});
        return ans;
    }
};