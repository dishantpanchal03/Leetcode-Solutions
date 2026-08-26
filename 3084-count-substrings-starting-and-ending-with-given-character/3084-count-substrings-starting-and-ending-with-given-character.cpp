class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long m = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s.at(i) == c)
                m++;
        }
        return m * (m + 1) / 2;
    }
};