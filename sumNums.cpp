class Solution{
    public:
        static int temp;
        static int sum;
        //static关键字相当于记录作用 不会重新初始化
        Solution(){
            ++temp;
            sum+=temp;
        }
        //静态成员函数没有this指针，它无法访问属于类对象的非静态数据成员，也无法访问非静态成员函数，它只能调用其余的静态成员函数
        //出现在类体外的函数定义不能指定关键字static
        //非静态成员函数可以任意地访问静态成员函数和静态数据成员
        static void again(){
            temp = 0;
            sum = 0;
        }
        int sumNums(int n){
            again();  //这里是为了防止它创建一个对象时，会自动的调用构造函数，从而导致多加了一次错误
                       //并且在多次调用得到不同的n对应的sum的时候会出错。在这里我们要防止这种情况
            Solution* arr = new Solution[n];
            delete[] arr;
            return sum;
        }
};
int Solution::temp = 0;
int Solution:: sum = 0;
//静态数据成员存储在全局数据区，静态数据成员在定义时分配存储空间，所以不能在类声明中定义
//静态数据成员是类的成员，无论定义了多少个类的对象，静态数据成员的拷贝只有一个，且对该类的所有对象可见。
//静态数据成员不属于任何对象，在没有类的实例时其作用域就可见，在没有任何对象时，就可以进行操作
//静态数据成员的初始化格式：<数据类型><类名>::<静态数据成员名>=<值>

class A;
A*arr[2];
class A {
    public:
        virtual int sum(int n){
            return 0;
        }
};
class B : public A{
    public:
        virtual int sum(int n){
            return n + arr[!!n]->sum(n-1);
        }
};

class Solution{
    public:
        int sumNums(int n){
            A a;
            B b;
            arr[0] = &a;
            arr[1] = &b;
            int ret = arr[1]->sum(n);
            return ret;

        }
}