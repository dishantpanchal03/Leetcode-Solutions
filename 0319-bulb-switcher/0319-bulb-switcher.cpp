class Solution {
public:
    int bulbSwitch(int n) {
        // if(n<2) return n;

        // vector<int> arr(n, 1);

        // for(int i=2; i<=n; i++){
        //     for(int j=i; j<=n; j+=i){
        //         arr[j-1] = !arr[j-1];
        //     }
        // }
        // int res = count(arr.begin(), arr.end(), 1);
        // return res;

        return sqrt(n);
    }
};