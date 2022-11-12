class Solution {
public:
    int lastRemaining(int n, int m) {
        //dp[i] = (dp[i - 1] + m) % i
        int x = 0;
        for(int i = 2; i <= n; i++){
            x = (x + m) % i;
        }
        return x;
    }
};