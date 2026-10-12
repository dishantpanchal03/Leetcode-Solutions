class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(30, 0);

        // Count the occurrences of each set bit
        for (int num : nums) {
            for (int bit = 0; bit < 30; bit++) {
                if (num & (1 << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Greedily construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 30; bit++) {
                if (cnt[bit] > 0) {
                    x |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return (int)ans;
    }
};