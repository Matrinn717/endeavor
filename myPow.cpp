class Solution {
public:
    double myPow(double x, int n) {
        //快速幂
        bool flag = false;
        long long N = n;
        if(N == 0) return 1;
        if(N < 0 ) flag = true, N = -N;
        double ret = 1;
        for(int i = 0; i < 32; ++i){
            
            if((1 << i) & N ) ret *= x;
           //1 左移 i位
            x = x * x;
        }

        if(flag ) return 1.0 / ret;
        else return ret;
    }
};

class Solution{
    public:
        double myPow(double x, int n){
            long a = n;
            if(x == 0.0 && n < 0)
                return 0.0;
            double res = 1.0;
            // c++中负数的右移操作不是简单除2，所以a要先转换成非负
            if(n < 0){
                x = 1 / x;
                a = -a;
        
            }
            while(a != 0){
                if(a & 1 == 1) //当a位奇数是， 向下取整会多一项x
                    res *= x;
                x *= x;
                a >>= 1;
            }
            return res;
        }
}