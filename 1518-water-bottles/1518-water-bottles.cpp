class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = full;

        while(empty >= numExchange){
            int n = empty / numExchange;
            int rem = empty % numExchange;
            empty = n + rem;
            full += n;
        }
        return full;
    }
};