class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) 
    {
        long long int ans = 0;
        long long int s = 0, e = 1e8;
        while(s <= e)
        {
            long long int mid = (s+e)/2;
            long long int running_cnt = 0, used = 0;
            queue <vector <long long int>> q;
            for(long long int i = 0; i<arr.size(); i++)
            {
                if(arr[i]  + running_cnt < mid)
                {
                    q.push({mid-arr[i]-running_cnt,i});
                    used += (mid - arr[i] - running_cnt);
                    long long int tp = (mid - arr[i] - running_cnt);
                    running_cnt += tp;
                }
                if(q.size() && q.front()[1] + w - 1 == i)
                {
                    running_cnt -= q.front()[0];
                    q.pop();
                }
            }
            if(used <= k)
            {
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return (int)ans;
    }
};