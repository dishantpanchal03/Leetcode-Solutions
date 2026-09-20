class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            res += (i + 1) * (123 - (int)s[i]);
        }
        return res;
    }
};