class Solution {
//        (1) 必须有0-9的数位，可出现在除"E34+"情况外的任何位置
//        (2) 小数点唯一，且必须在e或E之前
//        (3) e或E必须唯一，且之前必须有数位
//        (4) 正负号只能出现在第一个位置，或出现在'e'或'E'的后面一个位置
//        (5) 其它字符均为不合法字符
private:
 // 整数的格式可以用[+|-]B表示, 其中B为无符号整数
    bool scanInterger(const string s, int& index){
        if(s[index] == '+' || s[index] == '-') 
            ++index;
        return scanUnisignedInteger(s, index);
    }

    bool scanUnisignedInteger(const string s, int& index){
        int befor = index;
        while(index != s.size() && s[index] >= '0' && s[index] <= '9')
            index++;
        return index > befor;
    }
public:
 // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
    bool isNumber(string s) {
        if(s.size() == 0)
            return false;
        int index = 0;
         //字符串开始有空格，可以返回true
        while(s[index] == ' ')
            ++index;

    bool numeric = scanInterger(s,index);
     // 如果出现'.'，接下来是数字的小数部分
    if(s[index] == '.'){
        ++index;
         // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedInteger(s, index) || numeric;
    }
    // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
    if(s[index] == 'e' || s[index] == 'E'){
        ++index;
         // 下面一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(s, index);
    }
     //字符串结尾有空格，可以返回true
    while(s[index] == ' ')
        ++index;
    return numeric && index == s.size();
    }
};
