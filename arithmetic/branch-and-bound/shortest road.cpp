#include<bits/stdc++.h>
using namespace std;
#define MAX 9999//路径间最大距离
#define N 60
int n, dist[N], a[N][N];//n为顶点个数 dist为起点到各个顶点的距离 a为路径矩阵
int best[N]={0};
class HeapNode
{
public:
    int i, length,pre[N]={0};
    HeapNode() {}
    HeapNode(int ii, int l)
    {
        i = ii;
        length = l;
    }
    bool operator<(const HeapNode &node) const
    {
        return length < node.length;
    }
};

void shorest(int v)
{
    priority_queue<HeapNode> heap;
    HeapNode enode(v, MAX);
    for (int i = 1; i <= n; i++)
        dist[i] = MAX;
    dist[v] = 0;

    while (1)
    {
        for (int j = 1; j <= n; j++)
            if (a[enode.i][j] < MAX && a[enode.i][j]>0 && enode.length + a[enode.i][j] < dist[j])
            {
                dist[j] = enode.length + a[enode.i][j];
                //cout<<j<<" "<<dist[j]<<endl;
                HeapNode node(j, dist[j]);
                memcpy(node.pre,enode.pre,sizeof(enode.pre));
                node.pre[j]=enode.i;
                //for(auto i:node.pre)cout<<i<<" ";
                //cout<<endl;
                memcpy(best,node.pre,sizeof(best));
                heap.push(node);
            }
        if (heap.empty())
        {
            break;
        }
        else
        {
            enode = heap.top();
            heap.pop();
        }
    }
}
int main()
{
    int x;
    cout << "请选择输入方式：\n1.从文件shortroad.txt中输入\n2.手动输入\n";
    cin >> x;
    if (x == 1)
    {
        ifstream input("shortroad.txt");
        if (!input)
        {
            cout << "文件不存在" << endl;
            cout << "退出程序" << endl;
            system("pause");
            return 0;
        }
        input>>n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                input >> a[i][j];
                if (a[i][j] == -1)
                    a[i][j] = MAX;
            }
        input.close();
        cout<<"读取到 "<<n<<" 个点的路径矩阵为:"<<endl;
         for (int i = 1; i <= n; i++)
         {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == MAX)
                cout<<"-1 ";
                else cout<<a[i][j]<<" ";
            }       
            cout<<endl;
         }
    }
    else if (x == 2)
    {
        cout << "请输入点的个数：";
        cin >> n;
        cout << "\n请输入点与点之间的路径矩阵（不可达为-1）：\n";
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == -1)
                    a[i][j] = MAX;
            }
    }
    else
    {
        cout << "输入错误，退出程序！" << endl;
        system("pause");
        return 0;
    }
    shorest(1);
    cout << "源点到其他点的最短距离为：" << endl;
    for (int i = 2; i < n; i++)
        cout << dist[i] << " ";

    cout<<endl;
    cout << "源点到终点的最短距离为：" << endl;
    cout << dist[n] << endl;
    cout << "源点到终点的最短路径为：" << endl;
    int i=1;    
    cout<<i<<" -> ";
    while(i<n&& i>0)
    {
        if(best[i]==0||best[i]==n)
        {
            cout<<n;
            break;
        }
        cout<<best[i]<<" -> ";
        i=best[i]>0?best[i]:n;
    }
    cout<<endl;
    system("pause");
    return 0;
}

/*
5
0 10 -1 30 100
-1 0 50 -1 -1
-1 -1 0 -1 10
-1 -1 20 0 60
-1 -1 -1 -1 0
*/