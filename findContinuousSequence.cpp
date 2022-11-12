class Solution {
public:
    //连续正整数序列的左边界i，有边界j
    //此序列的元素和target = 元素平均值(i + j)/ 2 * 元素数量 (j - i + 1)
    //j = (-1 + sqrt(1 + 4 * (2 * target + (long) i * i - i))) / 2;
    vector<vector<int>> findContinuousSequence(int target) {
        //i左边界 j右边界
        int i = 1;
        double j = 2.0;
        vector<vector<int>> res;//定义二维数组
        while(i < j){
            j = (-1 + sqrt(1 + 4 * (2 * target + (long) i * i - i))) / 2;
            if(i < j && j == (int) j){ // 1.i < j 要求有至少两个数 2.j为整数的时候记录值
                vector<int> ans;
                for(int k = i; k <= (int)j; k++)
                    ans.push_back(k);//从i到j加入数组中 
                res.push_back(ans);
            }
            i++;
        }
        return res;
    }
};