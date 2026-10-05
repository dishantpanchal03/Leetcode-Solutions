class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        string s = "";

        for(int i=0; i<n; ){
            char curr = chars[i];
            int count = 0;

            while(i<n && chars[i] == curr){
                count++;
                i++;
            }
            s += curr;
            if(count > 1)
                s += to_string(count);
        }
        if(n < s.size()) return n;
        else{
            for(int x = 0; x < s.size(); x++){
                chars[x] = s[x];
            }
        }
        return s.size();
    }
};