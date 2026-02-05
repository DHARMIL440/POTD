class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int ans = 0, left = 0, right = 0, cnt = 0;
        while(right < arr.size())
        {
            if(arr[right] == 0) cnt++;
            while(cnt > k) 
            {
                if(arr[left] == 0) cnt--;
                left++;
            }
            ans = max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};
