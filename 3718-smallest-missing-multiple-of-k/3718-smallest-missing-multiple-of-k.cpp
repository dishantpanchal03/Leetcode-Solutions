class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool found = false;
        int i = 1;
        while(!found){
            if(find(nums.begin(), nums.end(),k * i) != nums.end()){
                i++;
            }
            else{
                return k * i;
            }
            
        }
        return 0;
    }
};