class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector <int> last(k);
        for(int i=0; i<k; i++){
            last[i] = nums[n-k+i];
        }
        for(int i=n-1; i>=k; i--){
            nums[i] = nums[i-k];
        }
        for(int i=0; i<k; i++){
            nums[i] = last[i];
        }
    }
};