#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int a[N],b[N],n;
struct Node{
    int v,i,j;
    friend bool operator<(Node a,Node b){
        return a.v>b.v;
    }
};
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    priority_queue<Node>q;
    for(int i=1;i<=n;i++){
        q.push({a[i]+b[1],i,1});
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",q.top().v);
        int x=q.top().i,y=q.top().j;
        q.pop();
        if(y+1<=n){
            q.push({a[x]+b[y+1],x,y+1});
        }
    }
    system("pause");
    return 0;
}
