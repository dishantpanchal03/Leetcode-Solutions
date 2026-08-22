class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;

        int num = n;

        while(n> 0){
            int rem = n % 10;
            sum += rem;
            mul *= rem;
            n /= 10;
        }
        if(num % (sum + mul) == 0){
            return true;
        }
        return false;
    }
};