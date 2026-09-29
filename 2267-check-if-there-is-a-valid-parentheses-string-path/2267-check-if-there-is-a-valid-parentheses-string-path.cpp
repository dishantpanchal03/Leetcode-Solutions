class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& g, int i, int j, int bal) {
        if (bal < 0) return false;
        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool ok = false;

        if (i + 1 < m)
            ok |= solve(g, i + 1, j, bal + (g[i + 1][j] == '(' ? 1 : -1));

        if (j + 1 < n)
            ok |= solve(g, i, j + 1, bal + (g[i][j + 1] == '(' ? 1 : -1));

        return dp[i][j][bal] = ok;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        if ((m + n - 1) % 2)
            return false;

        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n, -1)));

        return solve(grid, 0, 0, 1);
    }
};
