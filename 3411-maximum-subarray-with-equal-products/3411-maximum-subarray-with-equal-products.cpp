
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long gcdVal = 0, lcmVal = 1;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                gcdVal = gcd(gcdVal, (long long)x);

                long long g = gcd(lcmVal, (long long)x);
                lcmVal = (lcmVal / g) * x;

                product *= x;

                if (product == gcdVal * lcmVal) {
                    ans = max(ans, j - i + 1);
                }

                if (product > 25200) break;
            }
        }

        return ans;
    }
};
