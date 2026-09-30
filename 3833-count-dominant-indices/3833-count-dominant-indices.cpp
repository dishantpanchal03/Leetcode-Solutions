class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum = accumulate(nums.begin()+1, nums.end(), 0);
        for(int i=0; i<n-1; i++){
            if(i != 0)
                sum -= nums[i];
            int avg = sum / (n -i -1);
            if(nums[i] > avg) count++;
        }
        return count;
    }
};