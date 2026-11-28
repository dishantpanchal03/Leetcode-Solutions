class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = INT_MAX;
        vector<int> freq(n + 1), total(n + 1);

        for (auto& x : items) {
            freq[x[0]]++;
            mn = min(mn, x[1]);
        }

        total = freq;

        for (int i = 1; i <= n; i++)
            for (int j = 2 * i; j <= n; j += i)
                total[i] += freq[j];

        sort(items.begin(), items.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        long long ans = 0;

        for (auto& x : items) {
            int f = x[0], p = x[1];

            if (p >= 2LL * mn) break;

            long long cnt = min((long long)total[f] - 1,
                                (long long)budget / p);

            ans += 2 * cnt;
            budget -= cnt * p;
        }

        return ans + budget / mn;
    }
};
