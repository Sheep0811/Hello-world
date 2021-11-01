#include<bits/stdc++.h>
using namespace std;

int main()  
{
    char c,s[100001];
    int a=0,b=0,num=0;
    while(cin>>c)    
    {
        if(c=='E')break;
        else s[num++]=c;
    }
    for(int i=0;i<num;i++)
    {
        if(s[i]=='W')
        a++;
        else if(s[i]=='L')
        b++;
        if(a>=11 && a>b && a-b>=2 || b>=11 && b>a && b-a>=2)
        {
            cout<<a<<":"<<b<<endl;
            a=0;
            b=0;
        }
    }
    cout<<a<<":"<<b<<endl<<endl;
    a=0;
    b=0;
    for(int i=0;i<num;i++)
    {
        if(s[i]=='W')
        a++;
        else if(s[i]=='L')
        b++;
        if(a>=21 && a>b && a-b>=2 || b>=21 && b>a && b-a>=2)
        {
            cout<<a<<":"<<b<<endl;
            a=0;
            b=0;
        }
    }
    cout<<a<<":"<<b<<endl;
    return 0;
} 