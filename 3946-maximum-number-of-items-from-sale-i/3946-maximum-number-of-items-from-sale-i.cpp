
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        vector<int> weight(n);

        for (int i = 0; i < n; i++) {
            weight[i] = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && items[i][0] <= items[j][0] &&
                    items[j][0] % items[i][0] == 0) {
                    weight[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b],
                            dp[b - price] + weight[i]);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }

        return ans;
    }
};
