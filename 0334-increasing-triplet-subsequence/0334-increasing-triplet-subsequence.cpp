class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        int third = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i];

            if(n <= first) first = n;
            else if (n <= second) second = n;
            else{
                third = n;
                return true;
            }
        }
        return false;
    }
};