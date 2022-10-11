class Solution {
public:
    int translateNum(int num) {
        string str= to_string(num);
        int len=str.size();
        if(len<2) return len;
        vector<int> dp(len+1);
        dp[1]=1;//dp[2]=2 dp[1]=1 d[2]=dp[1]+dp[0];
        dp[0]=1;//dp[0]=1;
        for(int i =2; i<=len;i++){
            if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<='5'))
                dp[i]=dp[i-2]+dp[i-1];
            else dp[i]=dp[i-1];
        }l
        return dp[len];
    }
};