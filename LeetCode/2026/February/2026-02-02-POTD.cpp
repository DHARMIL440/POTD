class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        if (k == 1) return nums[0];

        multiset<int> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;


        auto add = [&](int x) {
            if (small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else {
                auto it = prev(small.end());
                if (*it > x) {
                    sumSmall -= *it;
                    large.insert(*it);
                    small.erase(it);
                    small.insert(x);
                    sumSmall += x;
                } else {
                    large.insert(x);
                }
            }
        };

        auto remove = [&](int x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto jt = large.begin();
                    sumSmall += *jt;
                    small.insert(*jt);
                    large.erase(jt);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        for (int i = 1; i <= dist + 1 && i < n; i++) {
            add(nums[i]);
        }
        ans = sumSmall;
        for (int i = 2; i < n; i++) 
        {
            remove(nums[i - 1]);

            if (i + dist < n) {
                add(nums[i + dist]);
            }

            if (small.size() == k - 1) {
                ans = min(ans, sumSmall);
            }
        }

        return nums[0] + ans;
    }
};
