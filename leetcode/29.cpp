class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        if(divisor==1)return dividend;
        if(divisor==-1){
            if(dividend>INT_MIN) return -dividend;// ֻҪ������С���Ǹ�����������ֱ�ӷ����෴���ͺ���
            return INT_MAX;// ����С���Ǹ����Ǿͷ�������������
        }
        int flag=0;
        if(!(dividend>=0 && divisor>0) || (dividend<=0 && divisor<0))flag=1;
        long a=abs(dividend),b=abs(divisor);
        if(b>a)return 0;

    }
       int div(long a, long b){  // �ƺ�������ѵ�����������⼸��
        if(a<b) return 0;
        long count = 1;
        long tb = b; // �ں���Ĵ����в�����b
        while((tb+tb)<=a){
            count = count + count; // ��С�ⷭ��
            tb = tb+tb; // ��ǰ���Ե�ֵҲ����
        }
        return count + div(a-tb,b);
    }
};