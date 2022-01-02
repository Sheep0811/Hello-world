#include <bits/stdc++.h>
using namespace std;
#define N 12000
int n;				//物品数量
double c;			//背包容量
double v[N];		//各个物品的价值　value
double w[N];		//各个物品的重量　weight
double cw = 0.0;	//当前背包重量　current weight
double cp = 0.0;	//当前背包中物品总价值　current value
double bestp = 0.0; //当前最优价值best price
double perp[N];	//单位物品价值(排序后) per price
int order[N];		//物品编号
bool put[N]={false};//设置是否装入，为1的时候表示选择该组数据装入，为0的表示不选择该组数据
bool tmp[N]={false};//暂存装入的数据

double bound(int i);//计算上界函数，功能为剪枝
void knapsack(); //按单位价值排序
void backtrack(int i);//回溯函数

int main()
{
	int x;
	cout << "请选择输入方式：\n1.从文件0-1bag.txt中输入\n2.手动输入\n";
	cin >> x;
	if (x == 1)
	{
		ifstream input("0-1bag.txt");
		if (!input)
		{
			cout << "文件不存在" << endl;
			cout << "退出程序" << endl;
			system("pause");
			return 0;
		}
		input >> c >> n;
		for (int i = 1; i <= n; ++i)
		{
			input >> w[i];
			order[i] = i;
		}
		for (int i = 1; i <= n; ++i)
			input >> v[i];
		cout << "读取到" << n << "个物品"
			 << "放入容量为" << c << "的背包中" << endl;
		cout << "重量分别为:";
		for (int i = 1; i <= n; ++i)
			cout << w[i] << " ";
		cout << endl;
		cout << "价值分别为:";
		for (int i = 1; i <= n; ++i)
			cout << v[i] << " ";
		cout << endl;
		input.close();
	}
	else if (x == 2)
	{

		cout << "请输入背包最大容量:" << endl;
		cin >> c;
		cout << "请输入物品个数:" << endl;
		cin >> n;
		cout << "请依次输入物品的重量:" << endl;
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			order[i] = i;
		}
		cout << "请依次输入物品的价值:" << endl;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
	}
	else
	{
		cout << "输入错误，退出程序！" << endl;
		system("pause");
		return 0;
	}
    clock_t start,end;  
	start=clock();
	knapsack();
	backtrack(1);
    end=clock();
	cout<<"最优价值为："<<bestp;
	cout<<"\n需要装入的物品编号是：";
	for (int i = 1; i <= n; i++)
	{
		if (put[i])
			cout <<order[i]<<" ";
	}
    cout<<"\n运行时间为："<<(int)end-start<<"ms"<<endl;
	cout << endl;
	system("pause");
	return 0;
}

void knapsack() //按单位价值排序
{
	int i, j;
	//int temporder = 0;
	//double temp = 0.0;

	for (i = 1; i <= n; i++)
		perp[i] = v[i] / w[i]; //计算单位价值（单位重量的物品价值）
	for (i = 1; i <= n - 1; i++)
	{
		for (j = i + 1; j <= n; j++)
			if (perp[i] < perp[j]) //排序perp[],order[],sortv[],sortw[]
			{
				swap(perp[i],perp[j]);//对perp[]排序

				swap(order[i],order[j]); //对order[]排序

				swap(v[i],v[j]);//对v[]排序

				swap(w[i],w[j]); //对w[]排序
			}
	}
	cout<<endl;
	for(int i=1;i<=n;++i)
	cout<<w[i]<<" ";	
	cout<<endl;
	for(int i=1;i<=n;++i)
	cout<<v[i]<<" ";
}

//回溯函数
void backtrack(int i)
{ //i用来指示到达的层数（第几步，从0开始），同时也指示当前选择完了几个物品
	if (i > n) //递归结束的判定条件
	{
		memcpy(put,tmp,sizeof(tmp));
		bestp=cp>bestp?cp:bestp;
		return;
	}
	//如若左子节点可行，则直接搜索左子树;
	//对于右子树，先计算上界函数，以判断是否将其减去
	if (cw + w[i] <= c) //将物品i放入背包,搜索左子树
	{
		cw += w[i]; //同步更新当前背包的重量
		cp += v[i]; //同步更新当前背包的总价值
		tmp[i] = true;
		backtrack(i + 1); //深度搜索进入下一层
		tmp[i] = false;
		cw -= w[i]; //回溯复原
		cp -= v[i]; //回溯复原
	}
	if (bound(i + 1) >= bestp) //如若符合条件则搜索右子树
		backtrack(i + 1);
}

//计算上界函数，功能为剪枝
double bound(int i)
{						   //判断当前背包的总价值cp＋剩余容量可容纳的最大价值<=当前最优价值
	double leftw = c - cw; //剩余背包容量
	double b = cp;		   //记录当前背包的总价值cp,最后求上界
	//以物品单位重量价值递减次序装入物品
	while (i <= n && w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	//装满背包
	if (i <= n)
		b += v[i] / w[i] * leftw;
	return b; //返回计算出的上界
}

/*
10
4 
4  7  5  3
40 42 25 12
*/
/*
30
3
16 15 15
40 25 25
*/