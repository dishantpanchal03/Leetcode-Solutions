class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        if(k == 1){
            int max = -1;
            for(int i=0; i<n; i++){
                if(mp[nums[i]] == 1 && nums[i] > max){
                    max = nums[i];
                }
            }
            return max;
        }

        n = n - 1;

        int n1 = nums[0];
        int n2 = nums[n];

        if(n1 == n2){
            return -1;
        }

        if(mp[n1] == 1 && mp[n2] == 1){
            return max(n1, n2);
        }

        if(mp[n1] == 1 && mp[n2] > 1){
            return n1;
        }
        if(mp[n2] == 1 && mp[n1] > 1){
            return n2;
        }
        
        return -1;
    }
};