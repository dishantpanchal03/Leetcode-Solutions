class Solution {
    public int addDigits(int num) {
        
        int n;
        while(num > 9) {
            int sum = 0;
        while(num > 0){
             n = num % 10;
             sum += n;
             num = num / 10;
        }
        num = sum;
        }
        return num;
    }
}