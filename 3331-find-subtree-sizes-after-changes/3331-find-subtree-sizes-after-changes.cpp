
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);

        vector<int> last(26, -1);

        function<void(int)> dfs1 = [&](int u) {
            int c = s[u] - 'a';

            int prev = last[c];

            if (prev != -1) {
                newParent[u] = prev;
            } else {
                newParent[u] = parent[u];
            }

            last[c] = u;

            for (int v : adj[u]) {
                dfs1(v);
            }

            last[c] = prev;
        };

        dfs1(0);

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        function<int(int)> dfs2 = [&](int u) {
            int size = 1;

            for (int v : tree[u]) {
                size += dfs2(v);
            }

            ans[u] = size;
            return size;
        };

        dfs2(0);

        return ans;
    }
};
