class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fs;
        unordered_map<char, int> ft;

        if(s.size() != t.size()){
            return false;
        }

        for(int i=0; i< s.length(); i++){
            fs[s[i]] += 1;
            ft[t[i]] += 1;
        }

        if(fs == ft){
            return true;
        }
        return false;
    }
};