class Solution {
public:
    string toHex(int num) {
        if(num==0)return "0";
        string ans;
        long long n=num;    
        if(n<0)n=(long long)(n+pow(2,32));
        while(n!=0)
        {
            long x=n%16;
            x>10?ans+=char(x-10+'a'):ans+=(char)x;
            n>>4;
        }
        return reverse(n.begin(),n.end());

    }
};