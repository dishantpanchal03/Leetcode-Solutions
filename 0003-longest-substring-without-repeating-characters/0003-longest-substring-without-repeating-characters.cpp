class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(256, -1);

        int left = 0, ans = 0;

        for(int right=0; right< s.size(); right++){
            if(lastseen[s[right]] >= left){
                left = lastseen[s[right]] + 1;
            }

            lastseen[s[right]] = right;
            ans = max(ans, right - left +1);
        }

        return ans;
    }
};