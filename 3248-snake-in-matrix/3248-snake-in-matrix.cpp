class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int res = 0;
        for(string com : commands){
            if(com == "DOWN") res += n;
            else if(com == "UP") res -= n;
            else if(com == "LEFT") res -= 1;
            else if(com == "RIGHT") res += 1;
        }
        return res;
    }
};