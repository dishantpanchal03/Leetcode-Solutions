class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        for(int i=2; i <= num/2; i++){
            long long sqr =(long long) i * i;
            if(sqr == num)
                return true;

            else if(sqr > num)
                return false;
        }
    //     float x = sqrt(num);
    //     int n = (int) x;

    //     if(n == x)
    //         return true;

    return false;
    }
};