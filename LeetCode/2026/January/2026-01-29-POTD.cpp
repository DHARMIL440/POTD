class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& orignal, vector<char>& changed, vector<int>& c) 
    {
        vector <vector <long long int>> cost(26,vector <long long int>(26,LONG_MAX));
        for(int i = 0; i<orignal.size(); i++) cost[orignal[i]-'a'][changed[i]-'a'] = min(cost[orignal[i]-'a'][changed[i]-'a'],c[i]*1LL);
        vector <vector <long long int>> dp(26,vector <long long int>(26,LONG_MAX));
        for(int i = 0; i<26; i++)
        {
            priority_queue <pair <long long int,int>,vector <pair <long long int,int>>,greater <pair <long long int,int>>> q;
            q.push({0LL,i});
            vector <int> vis(26,0);
            while(q.size())
            {
                long long int cst = q.top().first;
                int chr = q.top().second;
                q.pop();
                if(vis[chr]) continue;
                vis[chr] = 1;
                dp[i][chr] = min(dp[i][chr],cst);
                for(int j = 0; j<26; j++)
                {
                    if(!vis[j] && cost[chr][j] != LONG_MAX) q.push({cst+cost[chr][j],j});
                }
            }
        }

        long long int ans = 0;
        for(int i = 0; i<source.size(); i++) 
        {
            if(dp[source[i]-'a'][target[i]-'a'] == LONG_MAX) return -1;
            ans += dp[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};