class Solution{
    public:
        int findRepeatNumber(vector<int>& nums){
            unordered_map<int,bool> map;
            for(int num:nums){//将遍历的nums数组中的每一个元素，存储到num中
                if(map[num]) return num;
                map[num]=true;
            }
            return -1;
        }
}