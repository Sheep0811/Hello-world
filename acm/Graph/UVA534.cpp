#include<iostream>
#include<stdio.h>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;
double w[1000][1000];
int n,t=1;
struct u
{
    int x,y;
}a[1000];

void floyd()
{//经典的弗洛伊德算法 
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                w[i][j]=min(w[i][j],max(w[i][k],w[k][j]));
}

double d(int q,int p,int u,int y)
{//算两点距离 
    return sqrt(pow((q-u),2)+pow((p-y),2));
}

int main()
{
    while(cin>>n&&n)
    {
        memset(w,0x7f,sizeof(w));
        if(n==0)return 0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y;//输入 
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                w[i][j]=d(a[i].x,a[i].y,a[j].x,a[j].y);
            }
        }
        floyd();//使用弗洛伊德算法 
        cout<<"Scenario #"<<t<<endl;
        cout<<"Frog Distance = ";
        cout<<fixed<<setprecision(3)<<w[1][2]<<endl<<endl;//记得保留三位小数 
        t++;
    }
    system("pause");
    return 0;
} 