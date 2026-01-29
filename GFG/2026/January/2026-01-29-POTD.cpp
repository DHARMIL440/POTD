class Solution {
  public:
    string firstNonRepeating(string &a) 
    {
        queue <char> s;
        map <char,int> mp;
        string ans = "";
        for(int i = 0; i<a.size(); i++)
        {
            mp[a[i]]++;
            if(mp[a[i]] == 1) s.push(a[i]);
            while(s.size() && mp[s.front()] != 1) s.pop();
            if(s.size()) ans += (s.front());
            else ans += "#";
        }
        return ans;
    }
};