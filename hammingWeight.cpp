class Solution {
public://逐位判断
    int hammingWeight(uint32_t n) {
        int counts = 0;
        while(n){  //O(log2n) O(1)
            if(n & 1) ++counts;
            n >>= 1;
        }
        return counts;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
       int counts = 0;  //O(M) O(1)  M为二进制中1的个数
       while(n){ //n-1:将最右边的1变成0， 这个1右边的0都变成1
        n &= n - 1; //n & n-1 将最右边的1变成0 ，其余的不变
        ++counts;
       }
       return counts;
    }
};