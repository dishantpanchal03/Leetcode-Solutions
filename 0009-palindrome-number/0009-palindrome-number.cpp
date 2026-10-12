class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long int rev = 0;
        while(n>0){
        int rem = n % 10;
        rev = rev *10 + rem;
        n = n / 10;
        }
        if(rev == x){
            return true;
        }
        else{
            return false;
        }
    }
};