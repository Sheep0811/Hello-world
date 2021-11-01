#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100100;
int num,n,q;
int tre[maxn*4],lazy[maxn*4];//�߶��������飬���������飬�������ı�����˵����Ϊ�������Կ��ı���
//�����߶���
void Build(int l,int r,int rt)
{
    if(l==r)
    {//���l==r����Ҷ�ӣ�ֱ�Ӹ�ֵ
        tre[rt] = 1;//��ĿҪ���ʼΪ1
        return;
    }
    int mid = (l+r)/2;//ȡ�е�ֵ
    Build(l,mid,rt*2);
    Build(mid+1,r,rt*2+1);//�ݹ����ҽ���
    tre[rt] = tre[rt*2]+tre[rt*2+1];//���ݹ����и����ڵ㷵���ӽڵ����Ϣ
}
//�����ǵ����µ���
void pushDown(int l,int r,int rt)
{
    lazy[rt*2] = lazy[rt*2+1] = lazy[rt];//�������Ǵ���ԭ���ڵ����������
    int mid = (l+r)/2;//���ֳ����Ҷ���
    tre[rt*2] = (mid-l+1)*lazy[rt];
    tre[rt*2+1] = (r-mid)*lazy[rt];//���¶��ӵ�ֵ
    lazy[rt] = 0;//���½���ԭ���Ǹ���������ǿ�����ʧ��
}
//���߶������и��£���������һ�εĺ�
void Update(int x,int y,int z,int l,int r,int rt)
{
    if(x<=l&&y>=r)
    {
        tre[rt] = (r-l+1)*z;//������һ�������Ϣ
        lazy[rt] = z;//�����������������ǣ����������¸���
        return ;
    }
    if(lazy[rt])pushDown(l,r,rt);//�����Ҫ��������Ѱ�ң�����������Ǵ��ڣ���Ҫ���¸���
    int mid = l+r>>1;
    if(x<=mid)Update(x,y,z,l,mid,rt*2);//�������������Ҫ���ҵģ���Ҫ��������
    if(y>mid)Update(x,y,z,mid+1,r,rt*2+1);//ͬ������������к���Ҫ���ҵģ���Ҫ��������
    tre[rt] = tre[rt*2]+tre[rt*2+1];//���������ݷ��ظ����ڵ���Ϣ
}
int main()
{
    int i;
    int cases = 0;
    scanf("%d",&num);
    while(num--)
    {
        memset(tre,0,sizeof(tre));
        memset(lazy,0,sizeof(lazy));//�ȳ�ʼ��
        scanf("%d",&n);
        Build(1,n,1);//����
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