class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string next = "";

            for (int j = 0; j < s.length(); ) {
                int count = 0;
                char digit = s[j];

                while (j < s.length() && s[j] == digit) {
                    count++;
                    j++;
                }

                next += to_string(count);
                next += digit;
            }

            s = next;
        }

        return s;
    }
};