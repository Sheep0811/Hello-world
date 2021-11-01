#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
}a[1010];
int n;
int flag;
bool check(int x,int y)
{
    flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].x==x+1 && a[i].y==y){
            flag++;
        }
    
        if(a[i].x==x-1 && a[i].y==y){
            flag++;
        }
    
        if(a[i].x==x && a[i].y==y+1){
            flag++;
        }
    
        if(a[i].x==x && a[i].y==y-1){
            flag++;
        }
    }
    if(flag==4)return true;
    return false;
}
/*bool FindXY(int x, int y) {
	for (int i = 0; i < n; i++) {
		if (a[i].x == x && a[i].y == y)
			return true;
	}
	return false;
}
//判断给定的位置是否是垃圾回收站
bool check(node t) {
	if (FindXY(t.x - 1, t.y) && FindXY(t.x + 1, t.y)
		&& FindXY(t.x, t.y - 1) && FindXY(t.x, t.y + 1))
		return true;
	else
		return false;
}*/
int main()
{
   ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int ans[5]={0};
    int count=0;
    for(int i=0;i<n;i++){
        if(check(a[i].x,a[i].y)){
        count=0;
        int x1=a[i].x,y1=a[i].y;
        for(int i=0;i<n;i++){
        if(a[i].x==x1-1 && a[i].y==y1-1)
        count++;
        if(a[i].x==x1+1 && a[i].y==y1-1)
        count++;
        if(a[i].x==x1-1 && a[i].y==y1+1)
        count++;
        if(a[i].x==x1+1 && a[i].y==y1+1)
        count++;
        }
        ans[count]++;
    }
    }
    for(int i=0;i<5;i++){
        cout<<ans[i] <<endl;
        //cout<<ans[i]<<endl;
    }  
    system("pause");
    return 0;
}