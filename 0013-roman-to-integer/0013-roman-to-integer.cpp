class Solution {
public:
    int conv(char c)
    {
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else if(c == 'M')  return 1000;
        return 0;
    }
       
int romanToInt(string s) {
    int intval = 0;

    for(int i = 0; i < s.length(); i++) {
        int curr = conv(s[i]);
        int next = (i + 1 < s.length()) ? conv(s[i + 1]) : 0;

        if(curr < next) {
            intval += (next - curr);
            i++; 
        }
        else {
            intval += curr;
        }
    }

    return intval;
}
};