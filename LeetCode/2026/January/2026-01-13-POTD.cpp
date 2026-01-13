class Solution {
public:
    double separateSquares(vector<vector<int>>& a) {
        double start = 0, end = 1e12;
        double ans = 0;
        while (end - start > 1e-5)  
        {
            double mid = (start + end) / 2, sum_below = 0, sum_above = 0;
            for(int i = 0; i < a.size(); i++)
            {
                double tp = a[i][2];  

                if(a[i][1] + tp <= mid)
                {
                    sum_below += (tp * tp);
                }
                else if(a[i][1] >= mid)
                {
                    sum_above += (tp * tp);
                }
                else
                {
                    double below = (mid - a[i][1]) * tp;
                    double above = (a[i][1] + tp - mid) * tp;
                    sum_below += below;
                    sum_above += above;
                }
            }
            if(sum_below < sum_above)  
            {
                start = mid;
            }
            else
            {
                ans = mid;
                end = mid;
            }
        }
        return ans;
    }
};
