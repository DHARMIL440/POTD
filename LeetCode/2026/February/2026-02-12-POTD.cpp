class Solution {
public:
    int longestBalanced(string s) 
    {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int count = 0;
                int mn = 0;
                bool valid = true;

                for(int k = 0; k < 26; k++)
                {
                    if(freq[k] > 0)
                    {
                        if(mn == 0) mn = freq[k];
                        else if(freq[k] != mn)
                        {
                            valid = false;
                            break;
                        }
                        count++;
                    }
                }

                if(valid) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
