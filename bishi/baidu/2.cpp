#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    int len = s.length();
    int l1=-1,r1=-1,l0=-1,r0=-1;
    for(int i=0;i<len;++i)
    {
        if(s[i]=='1'){
            l1 = i+1;
            break;
        }
    }
    for(int i=0;i<len;i++){
        if(s[i]=='0'){
            l0=i+1;break;
        }
    }
        for(int i=len-1;i>=0;--i)
        {
            if(s[i]=='1'){
                r1=i+1;break;
            }
        }
        for(int i=len-1;i>=0;--i)
        {
            if(s[i]=='0'){
                r0=i+1;break;
            }
        }
        if(l1==-1 || r1==-1)
        {
            printf("%d %d %d %d",l0,r0-1,l0+1,r0);
            system("pause");
            return 0;
        }
        if(r0==-1 || r1==-1)
        {
            printf("%d %d %d %d",l1,r1-1,l1+1,r1);
            system("pause");
            return 0;
        }
        if(r0-l0>r1-l1)
        {
            printf("%d %d %d %d",l0,r0-1,l0+1,r0);
            system("pause");
            return 0;
        }else{
            printf("%d %d %d %d",l1,r1-1,l1+1,r1);
            system("pause");
            return 0;
        }
        
    system("pause");
    return 0;
}      