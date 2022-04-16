#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char mp[51][51];
int cnt[51][51];
int dr[]={-1,-1,0,1,1,1,0,-1},dc[]={0,1,1,1,0,-1,-1,-1};
int n,m;
void rev(char color,int dir,int x,int y)
{
    int tx=x+dr[dir],ty=y+dc[dir];
    if(tx<0 || tx>=n||ty<0||ty>=n)return;
    int mx=-1,my=-1;
    while(1)
    {
        if(mp[tx][ty]=='-')break;
        if(tx<0 || tx>=n)break;
        if(ty<0 || ty>=n)break;
        if(mp[tx][ty]!=color){
            mx=tx,my=ty;
        }
        tx+=dr[dir];
        ty+=dc[dir];
    }
    if(mx==-1||my==-1)
    return ;
    tx=x+dr[dir];
    ty=y+dc[dir];
    while(tx!=mx||ty!=my){
        if(cnt[tx][ty]!=m+1){
            cnt[tx][ty]=m;
            if(mp[tx][ty]=='w')
            mp[tx][ty]='b';
            else mp[tx][ty]='w';
        }
        tx+=dr[dir];
        ty+=dc[dir];
    }
}
void show()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%c",mp[i][j]);
        }
        puts("");
    }
    puts("END");
}
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        scanf("%*c%s",mp[i]);
        for(int j=0;j<n;++j)
        cnt[i][j]=1000000;
    }
    int x,y;
    char color ='w';
    while(m--)
    {
        scanf("%d%d",&x,&y);
        mp[x][y]=color;
        for(int i=0;i<8;++i)
        {
            rev(color,i,x,y);
        }
        if(color=='w')color='b';
        else color='w';
    }
    show();
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    system("pause");
    return 0;
}