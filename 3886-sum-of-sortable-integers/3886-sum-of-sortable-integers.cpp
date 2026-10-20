
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        auto check = [&](int k) -> bool {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Count descents inside this block,
                // including the circular last-to-first pair.
                int drops = prefDrop[end] - prefDrop[start];

                if (nums[end] > nums[start]) {
                    drops++;
                }

                if (drops > 1) {
                    return false;
                }

                // Ensure elements in earlier blocks can
                // precede elements in this block.
                if (start > 0 && prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        for (int d = 1; d <= n / d; d++) {
            if (n % d == 0) {
                if (check(d)) {
                    ans += d;
                }

                int other = n / d;
                if (other != d && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};
