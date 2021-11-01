class Solution {
public:
    int add(int a, int b) {
        while(b!=0)
        {
            int c=(unsigned int)(a&b)<<1;//C++中负数不支持左移位，因为结果是不定的 
            a^=b;
            b=c;
        }
        return a;
    }
};