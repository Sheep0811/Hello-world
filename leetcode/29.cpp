class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        if(divisor==1)return dividend;
        if(divisor==-1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        int flag=0;
        if(!(dividend>=0 && divisor>0) || (dividend<=0 && divisor<0))flag=1;
        long a=abs(dividend),b=abs(divisor);
        if(b>a)return 0;

    }
       int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
};