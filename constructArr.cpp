class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //表格上三角 和 下三角相乘法
        int len = a.size();
        if(len == 0) return {};
        vector<int> b(len, 1);
        b[0] = 1;
        int tmp = 1;
        for(int i = 1; i < len; i++){
            b[i] = b[i-1] * a[i-1]; // 下三角每一列相乘
        }
        for(int i = len - 2; i >= 0; i--){
            tmp *= a[i + 1];  //上三角从最底下开始乘
            b[i] *= tmp;
        }
        return b;
    }
};


