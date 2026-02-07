class Solution {
  public:
    int maxSum(vector<int> &a) 
    {
        int n = a.size();
        long long ans = 0, sum = 0;
        for (long long i = 0; i < n; i++) 
        {
            ans += (long long)(i * a[i]);
            sum += (long long)a[i];
        }
        long long max_ans = ans;
        long long tmp = ans;

        for (long long i = 1; i < n; i++) 
        {
            tmp = tmp - (long long)(sum - a[i-1]) + (long long)a[i-1] * (n - 1);
            if (tmp > max_ans) 
            {
                max_ans = tmp;
            }
        }
        return max_ans;
    }
};