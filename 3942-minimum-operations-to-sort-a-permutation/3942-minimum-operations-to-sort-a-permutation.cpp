class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), z = find(nums.begin(), nums.end(), 0) - nums.begin();
        int ans = INT_MAX;

        for (int s : {1, -1}) {
            bool ok = true;
            for (int i = 1; i < n; i++) {
                int a = (z + (i - 1) * s + n) % n;
                int b = (z + i * s + n) % n;
                if (nums[a] > nums[b]) ok = false;
            }

            if (ok) {
                if (s == 1) ans = min({ans, z, n - z + 2});
                else ans = min({ans, z + 2, n - z});
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};