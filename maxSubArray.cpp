class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+= nums[i-1]>0? nums[i-1]:0;
            res=res>nums[i]? res:nums[i];
        }
        return res;
};
// class Solution {
//     public int maxSubArray(int[] nums) {
//         int max = nums[0];
//         int former = 0;//用于记录dp[i-1]的值，对于dp[0]而言，其前面的dp[-1]=0
//         int cur = nums[0];//用于记录dp[i]的值
//         for(int num:nums){
//             cur = num;
//             if(former>0) cur +=former;
//             if(cur>max) max = cur;
//             former=cur;
//         }
//         return max;
//     }
// }

// class Solution {
//     public int maxSubArray(int[] nums) {
//         int res = nums[0];
//         for(int i = 1; i < nums.length; i++) {
//             nums[i] += Math.max(nums[i - 1], 0);
//             res = Math.max(res, nums[i]);
//         }
//         return res;
//     }
// }

