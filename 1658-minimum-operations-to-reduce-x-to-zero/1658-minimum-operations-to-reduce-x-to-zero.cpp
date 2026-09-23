class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        long long target = total - x;

        if(target == 0)
            return n;
        
        if(target < 0)
            return -1;

        int maxLen = -1;
        int i = 0;
        long long sum = 0;

        for(int j=i; j<n; j++){
            sum += nums[j];

            while(sum > target && i<j){
                sum -= nums[i++];
            }
            if(sum == target)
                maxLen = max(maxLen, j - i + 1);
        }
        return maxLen == -1? -1 : n - maxLen;
    }
};