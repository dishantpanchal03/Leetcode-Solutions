class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        int freq[10] = {0};

        for(int i=0; i<n; i++){
            freq[num[i] - '0']++;
        }

        for(int i=0; i<n; i++){
            if(freq[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};