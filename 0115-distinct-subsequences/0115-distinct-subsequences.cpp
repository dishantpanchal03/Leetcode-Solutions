class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    if (dp[j - 1] > INT_MAX - dp[j])
                        dp[j] = INT_MAX;
                    else
                        dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};