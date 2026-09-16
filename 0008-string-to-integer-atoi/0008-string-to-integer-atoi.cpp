class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int a = 0;
        long ans = 0; 
        int sign = 1; 

        while (a < size && s[a] == ' ') {
            a++;
        }

        if (a < size && (s[a] == '+' || s[a] == '-')) {
            if (s[a] == '-') {
                sign = -1;
            }
            a++;
        }

        while (a < size && s[a] >= '0' && s[a] <= '9') {
            int n = s[a] - '0';
            ans = ans * 10 + n;

            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            a++;
        }

        return ans * sign;
    }
};
