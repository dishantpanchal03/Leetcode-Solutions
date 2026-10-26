class Solution {
public:
    int m, n;
    long long sum;
    vector<vector<int>> vis;
    vector<vector<int>>* gridPtr;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int x, int y, int k) {
        vis[x][y] = 1;
        sum += (*gridPtr)[x][y];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                !vis[nx][ny] &&
                (*gridPtr)[nx][ny] != 0) {
                dfs(nx, ny, k);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));
        gridPtr = &grid;

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    sum = 0;
                    dfs(i, j, k);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};