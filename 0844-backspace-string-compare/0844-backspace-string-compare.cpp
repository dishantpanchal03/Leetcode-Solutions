class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string x = "";
        for(char c : s){
            if(c != '#'){
                x += c;
            }
            else if(c == '#' && !x.empty()){
                x.pop_back();
            }
        }

        string y = "";
        for(char c : t){
            if(c != '#'){
                y += c;
            }
            else if(c == '#' && !y.empty()){
                y.pop_back();
            }
        }
        return x == y;
    }
};