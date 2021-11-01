#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100100;
int num,n,q;
int tre[maxn*4],lazy[maxn*4];//线段树的数组，懒惰标记数组，开大于四倍（据说是因为经验所以开四倍）
//创建线段树
void Build(int l,int r,int rt)
{
    if(l==r)
    {//如果l==r到了叶子，直接赋值
        tre[rt] = 1;//题目要求初始为1
        return;
    }
    int mid = (l+r)/2;//取中点值
    Build(l,mid,rt*2);
    Build(mid+1,r,rt*2+1);//递归左右建树
    tre[rt] = tre[rt*2]+tre[rt*2+1];//回溯过程中给父节点返回子节点的信息
}
//懒惰标记的向下调整
void pushDown(int l,int r,int rt)
{
    lazy[rt*2] = lazy[rt*2+1] = lazy[rt];//把懒惰标记传给原来节点的两个儿子
    int mid = (l+r)/2;//划分出左右儿子
    tre[rt*2] = (mid-l+1)*lazy[rt];
    tre[rt*2+1] = (r-mid)*lazy[rt];//更新儿子的值
    lazy[rt] = 0;//更新结束原来那个点的懒惰标记可以消失了
}
//对线段树进行更新，这里是求一段的和
void Update(int x,int y,int z,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        tre[rt] = (r-l+1)*z;//更新这一区间的信息
        lazy[rt] = z;//并把这个点进行懒惰标记，不继续向下更新
        return ;
    }
    if(lazy[rt])pushDown(l,r,rt);//如果需要继续向下寻找，则如果懒惰标记存在，就要向下更新
    int mid = l+r>>1;
    if(x<=mid)Update(x,y,z,l,mid,rt*2);//如果左子树中有要查找的，就要遍历左树
    if(y>mid)Update(x,y,z,mid+1,r,rt*2+1);//同理如果右子树中含有要查找的，就要遍历右树
    tre[rt] = tre[rt*2]+tre[rt*2+1];//更新完后回溯返回给父节点信息
}
int main()
{
    int i;
    int cases = 0;
    scanf("%d",&num);
    while(num--)
    {
        memset(tre,0,sizeof(tre));
        memset(lazy,0,sizeof(lazy));//先初始化
        scanf("%d",&n);
        Build(1,n,1);//建树
        scanf("%d",&q);
        int x,y,z;
        while(q--)
        {
            scanf("%d%d%d",&x,&y,&z);
            Update(x,y,z,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",++cases,tre[1]);
    }
    system("pause");
    return 0;
}