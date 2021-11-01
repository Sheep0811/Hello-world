class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int flag=1;
        long long ans;
        while(s[i]==0)i++;
        if(s[i]=='-')flag=-1;
        if(s[i]=='-' ||s[i]=='+')i++;
        for(;i<s.size()&& s[i]>='0' && s[i]<='9';i++)
        {
            ans=ans*10+s[i]-'0';
            if (ans>INT_MAX && flag==1)return INT_MAX;

            if (ans>INT_MAX && flag==-1)return INT_MIN;

        }
        return ans*flag;
    }
};