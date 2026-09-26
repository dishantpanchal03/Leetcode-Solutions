class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(vector<string> k : knowledge){
            mp[k[0]] = k[1];
        }

        int i = 0;
        string ans;

        while(i < s.size()){
            if(s[i] == '('){
                int j = i+1;

                while(s[j] != ')')
                    j++;

                string key = s.substr(i+1, j-i-1);

                if(mp.find(key) != mp.end()){
                    ans += mp[key];
                }
                else{
                    ans += '?';
                }
                i = j + 1;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};