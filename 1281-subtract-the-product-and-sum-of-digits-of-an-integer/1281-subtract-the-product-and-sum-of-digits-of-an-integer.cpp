class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul=1, sum=0;
        while(n > 0){
            int rem = n % 10;
            sum += rem;
            mul *= rem;
            n /= 10;
        }
        return mul - sum;
    }
};