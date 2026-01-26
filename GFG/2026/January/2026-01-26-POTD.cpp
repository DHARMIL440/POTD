class Solution {
  public:
  
  
    void solve(vector <int> &arr, vector <int> &tmp, vector <vector <int>> &ans, vector <bool> &used)
    {
        if(tmp.size() == arr.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<arr.size(); i++)
        {
            
            if(used[i]) continue;
            tmp.push_back(arr[i]);
            
            used[i] = 1;
            solve(arr,tmp,ans,used);
            
            tmp.pop_back();
            used[i] = 0;
            
            if(i+1 < arr.size() && arr[i+1] == arr[i]) continue;
        }
        return ;
    }
    vector<vector<int>> permuteDist(vector<int>& arr) 
    {
        vector <vector <int>> ans;
        vector <int> tmp;
        vector <bool> used(arr.size(),0);
        sort(arr.begin(),arr.end());
        solve(arr,tmp,ans,used);
        return ans;
    }
};