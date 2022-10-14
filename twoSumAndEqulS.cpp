class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j = nums.size()-1;
        while(i<=j){
           
            if(nums[i]+nums[j] > target) j--;
            else if(nums[i] + nums[j] < target) i++;
            else return {nums[i], nums[j]};
        }
        return {};
    }
};
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i =0, j = nums.size()-1;
//         while(i<=j){
//             int m = (i+j)/2;
//             if(nums[i]+ nums[m] > target) j=m+1;
//             else if(nums[i] + nums[m] < target) i=m-1;
//             else return {nums[i], nums[m]};
//         }
//         return {};
//     }
// };