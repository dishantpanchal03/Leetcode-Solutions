class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i : nums){
            if(i == 0) zero++;
            else if(i == 1) one++;
            else two++;
        }

        int i = 0;
        while(zero > 0 || one > 0 || two > 0){
            if(zero > 0){
                nums[i] = 0;
                zero--;
            }
            else if(one > 0){
                nums[i] = 1;
                one--;
            }
            else{
                nums[i] = 2;
                two--;
            }
            i++;
        }
    }
};