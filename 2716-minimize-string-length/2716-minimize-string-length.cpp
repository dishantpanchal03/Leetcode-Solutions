class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> ans;

        for(char c : s) ans.insert(c);

        return ans.size();
    }
};