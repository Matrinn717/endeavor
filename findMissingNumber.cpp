// class Solution{  O(n) O(1)
//     public int missingNumber(int[] nums){
//         if(nums[0]==1) return 0;
//         for(int i=1;i<=num.length;i++){
//             if(num[i]!=i) return i;
//         }
//         return nums.length;
//     }
// }

class Solution { //O(logn) O(1)
public:
    int missingNumber(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int m =(left+right)/2;
            if(nums[m]==m) left=m+1;
            else right=m-1;
        }
        return left;
    }
};