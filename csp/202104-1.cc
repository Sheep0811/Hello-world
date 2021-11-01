#include<bits/stdc++.h>
int main()
{
    int n,m,L,a,i,j,q;
    int h[260]={0};
    scanf("%d%d%d",&n,&m,&L);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a);
            h[a]++;
        }
    }
    for(q=0;q<L-1;q++){
        printf("%d ",h[q]);
    }
    printf("%d",h[L-1]);
    system("pause");
    return 0;
}
