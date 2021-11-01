#include<bits/stdc++.h>
int n,f[1010];
int main()
{
    scanf("%d",&n);
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            f[i]+=f[j];
        }
        f[i]++;
    }
    printf("%d",f[n]);
    system("pause");
    return 0;
}