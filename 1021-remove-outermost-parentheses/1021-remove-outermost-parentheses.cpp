class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int bal = 0;
        for(char c : s){
            if(c == '('){
                if(bal > 0) ans += c;
                bal++;
            }
            else{
                bal--;
                if(bal > 0) ans += c;
            }
        }
        return ans;
    }
};