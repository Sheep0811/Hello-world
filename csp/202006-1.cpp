#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,num;
    int c;
};
node a[1005];
int main()
{
    int n,m,ans;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x1,y1;
        char s1;
        cin>>x1>>y1>>s1;
        if(s1=='A'){
            a[i].x=x1;
            a[i].y=y1;
            a[i].c=1;
        }
        else{
            a[i].x=x1;
            a[i].y=y1;
            a[i].c=-1;
        }
    }
    for(int j=0;j<m;j++){
        int a1,b1,c1;
        cin>>a1>>b1>>c1;
        ans=0;
        for(int i=0;i<n;i++){
            int re=a1+b1*a[i].x+c1*a[i].y;
            if(re>0)a[i].num=1;
            else a[i].num=-1;
            ans+=a[i].num*a[i].c;
            //printf(" %d",ans);
        }   
        //printf("%d",ans);
        if(ans==n||ans==0-n)printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}