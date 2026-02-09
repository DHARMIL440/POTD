class Solution {
  public:
    int findKRotation(vector<int> &arr) 
    {
        int ans = 0;
        int s = 1, e = arr.size()-1;
        while(s <= e)
        {
            int mid = (s+e)/2;
            if(arr[mid] >= arr[0])
            {
                ans = mid;
                s = mid+1;
            }
            else 
            {
                e = mid-1;
            }
        }
        if(ans == arr.size()-1) return 0;
        return ans + 1;
    }
};
