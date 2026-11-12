class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int curr = 1;

        if(n < 2)
            return n;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1])
                curr++;

            else
                curr = 1;

            maxi = max(maxi, curr);
        }

        curr = 1;

        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1])
                curr++;

            else
                curr = 1;

            maxi = max(maxi, curr);
        }

        return maxi;
    }
};