class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                int x = grid[i][j];

                if (i > 0) {
                    for (int v = 0; v < 1024; v++) {
                        if (dp[i - 1][j][v])
                            dp[i][j][v ^ x] = 1;
                    }
                }

                if (j > 0) {
                    for (int v = 0; v < 1024; v++) {
                        if (dp[i][j - 1][v])
                            dp[i][j][v ^ x] = 1;
                    }
                }
            }
        }

        for (int v = 0; v < 1024; v++) {
            if (dp[m - 1][n - 1][v])
                return v;
        }

        return 0;
    }
};