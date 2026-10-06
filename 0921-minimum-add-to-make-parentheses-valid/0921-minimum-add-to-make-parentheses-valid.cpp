class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;

        int n = 0;
        for(char c : s){
            if(c == '(') open++;
            else if(c == ')' && open > 0) open--;
            else n++;
        }
        return n + open;
    }
};