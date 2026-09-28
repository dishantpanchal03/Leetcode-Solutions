class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int curr = 0;

        for(char c : s){
            if(c == '('){
                curr++;
                depth = max(depth, curr);
            }
            else if(c == ')') curr--;
        }
        return depth;
    }
};