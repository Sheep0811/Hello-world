#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100000+5;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
typedef long long LL;
LL sum[maxn<<2],add[maxn];
int a[maxn];
struct node
{
    int l,r,m;
    LL sum,mark;
}t[maxn<<2];
 
void Build(int l,int r,int k)
{
    t[k].l=l;
    t[k].r=r;
    t[k].m=(l+r)/2;
    t[k].mark=0;
    if(l==r)
    {
        t[k].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    Build(l,mid,k*2);
    Build(mid+1,r,k*2+1);
    t[k].sum=(t[k<<1].sum+t[k*2+1].sum);
}

void Update(int l,int r,int k,int x)
{
    if(t[k].l==l&&t[k].r==r)
    {
        t[k].mark+=x;
        return;
    }
    t[k].sum+=(LL)x*(r-l+1);
    int mid=t[k].m;
    if(r<=mid)
        Update(l,r,k*2,x);
    else if(mid<l)
        Update(l,r,k*2+1,x);
    else
    {
        Update(l,mid,k*2,x);
        Update(mid+1,r,k*2+1,x);
    }
}

LL Query(int l,int r,int k)
{
    if(t[k].l==l&&t[k].r==r)
        return t[k].sum+t[k].mark*(LL)(r-l+1);
 
    if(t[k].mark!=0)
    {
        t[k*2].mark+=t[k].mark;
        t[k*2+1].mark+=t[k].mark;
         t[k].sum+=(LL)(t[k].r-t[k].l+1)*t[k].mark;//¼ÇµÃ+1
        t[k].mark=0;
    }
    int mid=t[k].m;
    if(mid>=r)
        return Query(l,r,k*2);
    else if(l>mid)
        return Query(l,r,k*2+1);
    else
        return Query(l,mid,k*2)+Query(mid+1,r,k*2+1);
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        Build(1,n,1);
        char ch[2];
        int x,y,z;
        while(m--)
        {
            scanf("%s",ch);
            if(ch[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                printf("%lld\n",Query(x,y,1));
            }
            else if(ch[0]=='C')
            {
                scanf("%d%d%d",&x,&y,&z);
                Update(x,y,1,z);
            }
        }
    }
    return 0;
}