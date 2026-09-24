class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            int n = nums[i];
            while(n > 0){
                int rem = n % 10;
                sum += rem;
                n /= 10;
            }
            if(sum == i)
                return i;
        }
        return -1;
    }
};