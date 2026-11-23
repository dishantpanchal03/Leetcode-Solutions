class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            bool flag = true;
                int x = i;
            while(x > 0){
                int rem = x % 10;
                if(rem == 0 || i % rem != 0){
                    flag = false;
                    break;
                }
                x /= 10;
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};