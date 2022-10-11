class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.size();
        if(length==0) return 0;
        if(length==1) return 1;
        vector<int> dp(length,0);
        dp[0]=1;
        int max=0;
        for(int i =1;i<length;i++){
            int j=i-1;
            while(j>=0 && s[i] !=s[j]) j--;
            //第j个字符不在dp[i-1]的区间内
            if(dp[i-1] < i-j) dp[i]=dp[i-1]+1;
            //第j个字符在dp[j-1]的区间内
            else dp[i]=i-j;
            if(dp[i]>max) max=dp[i];
        }
        return max;
    }
};
//dp[i]=dp[i-2]+dp[i-1] 如果最后两个字符不相等的话
//dp[i]=d[i-1]; 最后两个字符相等
//dp[0]=1;
//dp[1]=1;
