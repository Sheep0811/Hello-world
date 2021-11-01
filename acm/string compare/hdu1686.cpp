#include<stdio.h>
#include<stdlib.h>
#include<cstring>
char a[1000005],b[10005];
int kmp_next[10005];

void makenext(int m)
{
    
}


int kmp(int n, int m)
{
    int i,q,res = 0;
    makenext(m);
    for(int i,q=0;i<n;++i)
    {
        while(q>0 && b[q]!=a[i])
        q=kmp_next[q-1];
        if(b[q] == a[i])
        ++q;
        if(q == m)
        ++res;
    }
    return res;
    }

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",b,a);
        int n =strlen(a),m = strlen(b);
        printf("%d\n",kmp(n,m));
    }
    return 0;
}