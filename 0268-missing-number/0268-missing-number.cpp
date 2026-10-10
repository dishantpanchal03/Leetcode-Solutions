class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n+1) / 2;
        int curr = accumulate(nums.begin(), nums.end(), 0);

        return expected - curr;
    }
};