class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rSum = 0;

        for(int n : nums) rSum += n;

        int lSum = 0;

        for(int i=0; i<nums.size(); i++){
            rSum -= nums[i];

            if(rSum == lSum) return i;

            lSum += nums[i];
        }
        return -1;
    }
};