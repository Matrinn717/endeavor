class Solution {
public:
    int fib(int n) {
        int a =0,b=1,sum=0;
        //当n>1时才会进入循环，所以for循环算的是n从2到n+1的值
        for(int i =2;i<=n+1;i++){
            sum=(a+b)%1000000007;
            a=b;
            b=sum;
        }
        // 由于多算一次，所以返回的是a，不是b
        return a;
    }
};