class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        int a = n / 3, b = n % 3;
        if(b == 0) return pow(3, a);
        if(b == 1) return pow(3, a-1) * 4;
        return pow(3, a) * 2;
    }
};

class Solution {
public:
  /**
     * 1. 确定dp数组下标含义 分拆数字i，可以得到的最大乘积为dp[i];
     * 2. 递推公式 dp[i] = max(dp[i], (i - j) * j, dp[i - j] * j);
     * 3. 初始化 dp[2] = 1;
     * 4. 遍历顺序 从前向后遍历就可以;
     * 5. 推导结果;
     */
    int cuttingRope(int n) {
      
        /* 定义dp数组 */
        vector<int> dp(n + 1);
         /* dp数组初始化 */
        dp[2] = 1;
        /* 从前向后遍历 */
        for(int i = 3; i <= n; i++){
             /* j遍历到小于i的值 */
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max((i - j) * j), dp[i - j]);
            }
        }
        return dp[n];
    }
};