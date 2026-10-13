class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < 0) nums[i] = -(nums[i]);
        }
        sort(nums.begin(), nums.end());

        long long res = 0;

        for(int j = n-1; j>=n/2; j--){
            res += (nums[j] * nums[j]);
        }
        for(int k=0; k<n/2; k++){
            res -= (nums[k] * nums[k]);
        }
        return res;
    }
};