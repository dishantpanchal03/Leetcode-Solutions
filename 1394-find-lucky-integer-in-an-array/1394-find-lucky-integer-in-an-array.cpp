class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int a : arr){
            mp[a]++;
        }
        int ans = -1;
        for(auto &[x, count] : mp){
            if(x == count) ans = max(ans, x);
        }
        return ans;
    }
};