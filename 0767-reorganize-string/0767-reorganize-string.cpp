class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        int freq[26] = {};

        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = 0, maxChar = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        if (maxFreq > (n + 1) / 2) {
            return "";
        }

        string ans(n, ' ');
        int index = 0;

        while (freq[maxChar] > 0) {
            ans[index] = 'a' + maxChar;
            index += 2;
            freq[maxChar]--;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (index >= n) {
                    index = 1;
                }

                ans[index] = 'a' + i;
                index += 2;
                freq[i]--;
            }
        }

        return ans;
    }
};
