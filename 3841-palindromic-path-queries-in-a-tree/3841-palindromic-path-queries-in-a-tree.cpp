
class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, mask;
    vector<int> seg, lazy;
    int timer;

    void dfs(int u, int p) {
        tin[u] = timer++;
        up[0][u] = (p == -1 ? u : p);

        for (int k = 1; k < LOG; k++) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int k = LOG - 1; k >= 0; k--) {
            if (!isAncestor(up[k][u], v)) {
                u = up[k][u];
            }
        }

        return up[0][u];
    }

    void apply(int node, int val) {
        seg[node] ^= val;
        lazy[node] ^= val;
    }

    void push(int node) {
        if (lazy[node] != 0) {
            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end,
                int l, int r, int val) {
        if (r <= start || end <= l) return;

        if (l <= start && end <= r) {
            apply(node, val);
            return;
        }

        push(node);

        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid, end, l, r, val);
    }

    int query(int node, int start, int end, int idx) {
        if (end - start == 1) return seg[node];

        push(node);

        int mid = (start + end) / 2;

        if (idx < mid)
            return query(node * 2, start, mid, idx);

        return query(node * 2 + 1, mid, end, idx);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        mask.resize(n);
        timer = 0;

        dfs(0, -1);

        seg.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);

        // Build root-to-node XOR masks in Euler Tour order.
        vector<int> rootMask(n, 0);

        function<void(int, int, int)> buildRoot =
            [&](int u, int p, int current) {
                current ^= (1 << (s[u] - 'a'));
                rootMask[tin[u]] = current;

                for (int v : adj[u]) {
                    if (v != p) buildRoot(v, u, current);
                }
            };

        buildRoot(0, -1, 0);

        function<void(int, int, int, vector<int>&)> build =
            [&](int node, int start, int end, vector<int>& a) {
                if (end - start == 1) {
                    seg[node] = a[start];
                    return;
                }

                int mid = (start + end) / 2;
                build(node * 2, start, mid, a);
                build(node * 2 + 1, mid, end, a);
            };

        build(1, 0, n, rootMask);

        for (int u = 0; u < n; u++) {
            mask[u] = 1 << (s[u] - 'a');
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                if (delta != 0) {
                    // Every descendant's root-path XOR changes.
                    update(1, 0, n, tin[u], tout[u], delta);
                    mask[u] = newMask;
                }
            } else {
                ss >> v;

                int w = lca(u, v);

                int rootU = query(1, 0, n, tin[u]);
                int rootV = query(1, 0, n, tin[v]);

                int pathMask = rootU ^ rootV ^ mask[w];

                ans.push_back(
                    __builtin_popcount((unsigned)pathMask) <= 1
                );
            }
        }

        return ans;
    }
};
