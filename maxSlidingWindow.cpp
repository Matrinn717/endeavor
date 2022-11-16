class Solution{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k){
            int n = nums.size();
             //判断特殊情况
            if(n < k || k <= 0) return {};
            //滑动窗口的前后指针
            int low = 1 - k, high = 0;

            deque<int> dq; //双端队列，实现窗口
            vector<int> res;

            while(high < n){
                //判断滑窗的low端是否是最大的元素
                if(low >= 1 && nums[low - 1] == dq[0]) dq.pop_front();
                //小于nums[high]的元素出队
                //while循环dq[0]的值在不断变化
                while(!dq.empty() && dq[0] < nums[high]) dq.pop_front();
                //小于nums[high]的元素出队
                //while循环dq[dq.size() - 1]的值在不断变化
                while(!dq.empty() && dq[dq.size() - 1] < nums[high]) dq.pop_back();
                //两个while循环确保双向队列中为一个递减序列
                //队首为最大值



                //此时的high指针进队
                dq.push_back(nums[high]);

                //当low >= 0，滑窗已经形成
                if(low >= 0) res.push_back(dq[0]);
                low ++;
                high ++;
            } 
            return res;
        }
}