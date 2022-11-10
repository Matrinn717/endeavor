class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int max = 0, numth = 0;
        for(int num : nums){
            map[num]++;
            if(map[num] > numth){
                max = num;
                numth = map[num];
            }
        }
        return max;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       return nums[nums.size() / 2];
        
    }
};

class Solution{
    public:
    //假设有一个擂台，有一组人，每个人有编号，
    //相同编号为一组，依次上场，没人时上去的便是擂主（x），
    //若有人，编号相同则继续站着（人数+1），若不同，
    //假设每个人战斗力相同，都同归于尽，则人数-1；那么到最后站
    //着的肯定是人数占绝对优势的那一组啦~
        int majorityElement(vector<int>& nums){
            int x = 0, votes = 0, count = 0;
            for(int num : nums){//每一个人都要出来挑战
                if(votes == 0) x = num; //擂台上没人 选一个出来当擂主 x就是擂主  votes就是人数
                votes += num == x ? 1 : -1; //如果是自己人就站着呗 如果不是 就同归于尽
            }
            for(int num : nums)
                if(num == x) count++;
            return count > nums.size() / 2 ? x : 0;
        }
}
