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
{//����ĸ��������㷨 
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                w[i][j]=min(w[i][j],max(w[i][k],w[k][j]));
}

double d(int q,int p,int u,int y)
{//��������� 
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
            cin>>a[i].x>>a[i].y;//���� 
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                w[i][j]=d(a[i].x,a[i].y,a[j].x,a[j].y);
            }
        }
        floyd();//ʹ�ø��������㷨 
        cout<<"Scenario #"<<t<<endl;
        cout<<"Frog Distance = ";
        cout<<fixed<<setprecision(3)<<w[1][2]<<endl<<endl;//�ǵñ�����λС�� 
        t++;
    }
    system("pause");
    return 0;
} 