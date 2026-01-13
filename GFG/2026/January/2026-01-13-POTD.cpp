class Solution {
  public:
    bool canServe(vector<int> &arr) 
    {
        int cnt = 0, cnt1 = 0;
        for(int &i : arr)
        {
            if(i == 5) cnt++;
            else if(i == 10)
            {
                if(cnt > 0) cnt -= 1, cnt1++;
                else return false;
            }
            else
            {
                if(cnt >= 1 && cnt1 >= 1) cnt -= 1, cnt1 -= 1;
                else if(cnt >= 3) cnt -= 3;
                else return false;
            }
        }
        return true;
    }
};