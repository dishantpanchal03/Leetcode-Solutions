class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(char c : s){
            mp[c]++;
        }

        int ans = 0;
        int odd = 0;
        for(auto &[c, n] : mp){
            if(n % 2 == 0) ans += n;
            else{ 
                ans += n - 1;
                odd = 1;
            }
        }
        return ans + odd;
    }
};