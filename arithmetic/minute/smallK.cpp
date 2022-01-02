#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &a, int first, int end);//冒泡排序

void setting(vector<int> &Person, int n); //生成随机数

int partition(vector<int> &a, int p, int r, int x);//随机划分

int select(vector<int> &a, int p, int r, int k);//找第K小的数

void getNumberK(vector<int> &a, int k);//输出第k小的数

int main()
{
    int n=0;
    cout<<"请输入随机生成的数组长度"<<endl;
    cin>>n;
    label:;
    cout<<"请输入所求第K小的数K：";
    int k=0;
    cin>>k;
    if(k<=0 || k>n)
    {
        cout<<"输入错误,请再次输入"<<endl;
        goto label;
    }
    vector<int> a(n,0);
    setting(a,n);
    clock_t start,end;
    int time1;
    start=clock();
    getNumberK(a,k);
    end=clock();
    time1=end-start;
    start=clock();
    sort(a.begin(),a.end());
    cout<<"\n排序后第k个的元素为:"<<a[k-1]<<endl;
    end=clock();
    cout<<"线性时间选择所用时间为："<<time1<<"ms"<<endl;
    cout<<"排序后取值所用时间为："<<int(end-start)<<"ms"<<endl;
    cout<<"\n作为对照排序后的数组为：";
    for(int i=0;i<n;++i)cout<<"("<<i+1<<")"<<a[i]<<" ";
    system("pause");
    return 0;
}

void bubble(vector<int> &a, int first, int end)//冒泡排序
{
    for (int flag = first; flag < end; flag++)
        for (int i = end; i > flag; i--)
            if (a[i] < a[i - 1])
            {
                int t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
            }
}

int partition(vector<int> &a, int p, int r, int x)
{
    int i = p - 1, j = r + 1;
    while (true)
    {
        while (a[++i] < x && i < r);
        while (a[--j] > x && j > p);
        if (i >= j)break;
        swap(a[i],a[j]);
    }
    return j;
}

int select(vector<int> &a, int p, int r, int k)
{
    if (r - p < 75)
    {
        bubble(a, p, r);
        return a[p + k - 1];
    }
    for (int i = 0; i <= (r - p - 4) / 5; i++)
    {
        int s = p + 5 * i, t = s + 4;
        bubble(a, s, t);
        int temp = a[p + i];
        a[p + i] = a[s + 2];
        a[s + 2] = temp;
    }
    int x = select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10 + 1);
    int i = partition(a, p, r, x);
    int j = i - p + 1;
    if (k <= j)
        return select(a, p, i, k);
    else
        return select(a, i + 1, r, k - j);
}

void getNumberK(vector<int> &a, int k)
{
    int xk = select(a, 0, a.size() - 1, k);
    cout<<"\n第k小的元素为:"<<xk<<endl;
}

void setting(vector<int> &Person, int n) //生成随机数
{
    srand(time(NULL)); //通过时间给srand()提供一个种子
    for (int i = 0; i < n; i++)
    {
        Person[i] = rand() % 100000;
        //调用rand()，它会根据提供给srand()的种子值返回一个随机数
    }
   //cout << "\n随机生成的" << n << "个数为:";
  //  for (int i = 0; i < n; i++)
  //  {
  //       cout << Person[i] << " ";
  // }
}

