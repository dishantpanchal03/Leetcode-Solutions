class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);


        for (char c : s) {
            int idx = c - 'a';

            dp[idx] = (accumulate(dp.begin(), dp.end(), 0LL) +1) % MOD;
        }

        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    }
};