#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &nums, int l, int r);
int randompartition(vector<int> &nums, int l, int r);
void qsort(vector<int> &nums, int l, int r);
//快速排序

void sort(vector<int> &nums);
//冒泡排序（作为对比）

void setting(vector<int> & Person,int n);
//为数组生成随机数
int k=0;//是否输出排序前数组
int main()
{
    cout << "请输入数组随机生成的数组长度：" << endl;
    int n=0;
    cin>>n;
    vector<int> nums(n,0);
   // int tmp;
   // while (cin >> tmp)
   // {
   //     nums.push_back(tmp);
   //     if(cin.get()=='\n') break;
   // }
    k=1;
    setting(nums,n);
    k=0;
    clock_t start, end;
    int time1;
    start = clock();
    qsort(nums, 0, nums.size() - 1);
    end = clock();
    time1 = (int)(end - start);

  cout<<"\n快排排序序后的数组为：";
  for(int i:nums)
  {
   cout<<i<<" ";
  }

    setting(nums,n);
    start = clock();
    sort(nums);
    end = clock();
//     cout<<"\n冒泡排序序后的数组为：";
//  for(int i:nums)
//  {
//   cout<<i<<" ";
//  }
    cout << "\n快排用时为：" << time1 << "ms" << endl;
    cout << "冒泡排序用时为：" << (int)(end - start) << "ms" << endl;
    system("pause");
    return 0;
}

int partition(vector<int> &nums, int l, int r)
{
    int tmp = nums[l];
    int i = l + 1, j = r;
    while (true)
    {
        while (i <= j && nums[i] <= tmp)
            i++;
        while (i <= j && nums[j] >= tmp)
            --j;
        if (i >= j)
            break;
        swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[l]);
    return j;
}
int randompartition(vector<int> &nums, int l, int r)
{
    int i = rand() % (r - l + 1) + l;
    swap(nums[i], nums[l]);
    return partition(nums, l, r);
}
void qsort(vector<int> &nums, int l, int r)
{
    if (l < r)
    {
        int pos = randompartition(nums, l, r);
        qsort(nums, l, pos - 1);
        qsort(nums, pos + 1, r);
    }
}

void sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = n - 2; j >= i; j--)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}
void setting(vector<int>&Person,int n)//生成随机数
{
	srand(time(NULL));//通过时间给srand()提供一个种子
	for(int i=0;i<n;i++)
	{
		Person[i]=rand()%10000;
		//调用rand()，它会根据提供给srand()的种子值返回一个随机数
	}
    if(k==1)
    {
    cout<<"\n随机生成的"<<n<<"个数为:";
    for(int i=0;i<n;i++)
    {
	    cout<<Person[i]<<" ";
    } 
    }
  
}