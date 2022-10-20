class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int count_0 = 0;
        sort(nums.begin(),nums.end());
        for(int i =0; i < nums.size()-1; i++){
            if(nums[i] == 0) count_0++;
            else if(nums[i] == nums[i+1]) return false;

        }
        return nums[4] - nums[count_0] < 5;
    }
};