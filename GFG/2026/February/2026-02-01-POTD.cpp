class Solution {
  public:
  
    int solve(int ind, deque <vector <int>> &q, int k)
    {
        while(q.size())
        {
            int in = q.front()[1];
            if(ind - in + 1 <= k) return in;
            q.pop_front();
        }
        return ind;
    }
    vector<int> maxOfSubarrays(vector<int>& arr, int k) 
    {
        deque <vector <int>> q;
        vector <int> ans;
        for(int i = 0; i<arr.size(); i++)
        {
            while(q.size())
            {
                int el = q.back()[0];
                if(el <= arr[i])
                {
                    q.pop_back();
                }
                else break;
            }
            q.push_back({arr[i],i});
            if(i >= k-1)
            {
                int el = solve(i,q,k);
                ans.push_back(arr[el]);
            }
        }
        return ans;
    }
};

