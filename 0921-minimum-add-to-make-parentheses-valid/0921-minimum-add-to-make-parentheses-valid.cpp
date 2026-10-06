class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        int n = 0;
        for(char c : s){
            if(c == '(') st.push('(');
            else if(c == ')' && !st.empty()) st.pop();
            else n++;
        }
        return n + st.size();
    }
};