class Solution {
  public:
  
  
    int dig(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += (n % 10);
            n /= 10;
        }
        return ans;
    }
    int solve(int n, int d)
    {
        int s = 1, e = n;
        int ans = 0;
        while(s <= e)
        {
            int mid = (s+e)/2;
            int tans = mid - dig(mid);
            if(tans <  d)
            {
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return ans;
    }
    int getCount(int n, int d) 
    {
        return n - solve(n,d);
    }
};